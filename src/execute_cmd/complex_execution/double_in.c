/*
** PROJECT, 2022
** B-PSU-200-PAR-2-1-minishell2-yanis.djeridi
** File description:
** double_in.c
*/

#include "my.h"
#include "mysh.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <stdbool.h>

char **get_input_user(char *finish)
{
    char *input = NULL;
    size_t input_size = 0;
    int index = 0;
    char **user_input = malloc(sizeof(char *) * 100);

    my_printf("? ");
    while (getline(&input, &input_size, stdin) != -1) {
        if (my_strcmp(input, finish) == 0) {
            break;
        } else {
            my_printf("? ");
        }
        if (index == 100)
            break;
        user_input[index] = my_strdup(input);
        index++;
    }
    free(input);
    user_input[index] = NULL;
    return user_input;
}

char *get_finish_user(mysh_t *data, int i)
{
    int len = my_strlen(data->cmd[i + 1]);
    char *temp = my_strdup(data->cmd[i + 1]);
    char *finish = malloc(sizeof(char) * (len + 2));
    int index = 0;

    while (temp[index] != '\0') {
        finish[index] = temp[index];
        index++;
    }
    finish[index] = '\n';
    finish[index + 1] = '\0';
    free(temp);
    return finish;
}

void execute_in(mysh_t *data, complex_t *info, char *finish, int i)
{
    char *raw_cmd = my_strdup(info->av[0]);
    char **user_input = get_input_user(finish);

    info->ac = 0;
    complex_path(data->info->av, data->path, data->pwd);
    data->exit_code = double_in_execution(data, raw_cmd, user_input, i);
    free_tab(info->av);
    info->av = malloc(sizeof(char *) * (size_of_tab(data->cmd) + 1));
    info->status = false;
    free_tab(user_input);
    free(raw_cmd);
}

void double_in(mysh_t *data, complex_t *info, int *i)
{
    char *finish = get_finish_user(data, (*i));
    data->info->av[data->info->ac] = NULL;

    if (info->ac != 0) {
        execute_in(data, info, finish, (*i));
        free(finish);
        if (info->file != NULL) {
            free(info->file);
            (*i)++;
        }
        info->double_out = false;
        info->redirect_in = false;
    }
    info->status = true;
    (*i)++;
}
