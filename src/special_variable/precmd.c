/*
** PROJECT, 2022
** Shell
** File description:
** precmd.c
*/

#include "my.h"
#include "mysh.h"
#include <unistd.h>
#include <stdlib.h>

void reset_precmd(mysh_t *data, char *temp_cmd, char **temp_tab)
{
    free(data->raw_cmd);
    free_tab(data->cmd);
    data->raw_cmd = my_strdup(temp_cmd);
    data->cmd = my_tabdup(temp_tab);
    free(temp_cmd);
    free_tab(temp_tab);
}

void precmd(mysh_t *data)
{
    char *cmd = my_getenv(data->new_env, "PRECMD");
    char *temp_cmd = my_strdup(data->raw_cmd);
    char **temp_tab = my_tabdup(data->cmd);

    if (my_strcmp(cmd, "NULL") == 0) {
        free_tab(temp_tab);
        free(temp_cmd);
        free(cmd);
        return;
    }
    free(data->raw_cmd);
    free_tab(data->cmd);
    data->raw_cmd = my_strdup(cmd);
    data->cmd = my_str_to_word_array(cmd, ' ');
    free(cmd);
    complex_main(data);
    reset_precmd(data, temp_cmd, temp_tab);
}
