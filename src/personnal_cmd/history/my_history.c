/*
** PROJECT, 2022
** Shell
** File description:
** my_history.c
*/

#include <stdio.h>
#include <stdlib.h>
#include "mysh.h"
#include "my.h"

void reset_previous_cmd(mysh_t *data, char *temp_cmd, char **temp_tab)
{
    free(data->raw_cmd);
    free_tab(data->cmd);
    data->raw_cmd = my_strdup(temp_cmd);
    data->cmd = my_tabdup(temp_tab);
    free(temp_cmd);
    free_tab(temp_tab);
}

static void exec_previous_cmd(mysh_t *data, char *cmd)
{
    char *temp_cmd = my_strdup(data->raw_cmd);
    char **temp_tab = my_tabdup(data->cmd);

    free(data->raw_cmd);
    free_tab(data->cmd);
    data->cmd = my_str_to_word_array(cmd, ' ');
    data->raw_cmd = my_strdup(data->cmd[0]);
    classic_execution(data);
    reset_previous_cmd(data, temp_cmd, temp_tab);
}

static void exec_last_command(mysh_t *data, unsigned int *n)
{
    list_t *temp = NULL;
    history_t *history = NULL;
    unsigned int i = 1;

    temp = *data->history;
    if (temp->next == NULL) {
        return;
    }
    while (temp->next->next != NULL &&
        (n == NULL || *n != i)) {
        temp = temp->next;
        i++;
    }
    history = (history_t *)temp->data;
    if (history->cmd[1] != '!' && history->cmd[1] != '\0') {
        printf("%s\n", history->cmd);
        exec_previous_cmd(data, history->cmd);
    }
}

int my_previous_command(mysh_t *data)
{
    if (data->raw_cmd[1] == '!') {
        exec_last_command(data, NULL);
    } else {
        unsigned int n = strtoul(&data->raw_cmd[1], NULL, 10);
        exec_last_command(data, &n);
    }
    return 0;
}

int my_history(mysh_t *data)
{
    display_history(data);
    return 0;
}
