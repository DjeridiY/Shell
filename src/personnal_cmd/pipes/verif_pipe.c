/*
** PROJECT, 2022
** B-PSU-200-PAR-2-1-minishell2-yanis.djeridi
** File description:
** verif_pipe.c
*/

#include "my.h"
#include "mysh.h"
#include <signal.h>
#include <stdlib.h>

int verif_basic(char **cmd, int index)
{
    if (index == 0)
        return 1;
    if (my_strcmp(cmd[index - 1], "|") == 0
        || my_strcmp(cmd[index - 1], ">") == 0 ||
        my_strcmp(cmd[index - 1], "<") == 0 ||
        my_strcmp(cmd[index - 1], "<<") == 0 ||
        my_strcmp(cmd[index - 1], ">>") == 0 ||
        my_strcmp(cmd[index - 1], ";") == 0 ||
        my_strcmp(cmd[index - 1], "&&") == 0 ||
        my_strcmp(cmd[index - 1], "||") == 0) {
            return 1;
    }
    return 0;
}

int verif_cmd(char **cmd, int size, int i)
{
    if (my_strcmp(cmd[i], "|") == 0) {
        if (i + 1 == size)
            return 1;
        if (my_strcmp(cmd[i + 1], "|") == 0
        || my_strcmp(cmd[i + 1], ">") == 0 ||
        my_strcmp(cmd[i + 1], "<") == 0 ||
        my_strcmp(cmd[i + 1], "<<") == 0 ||
        my_strcmp(cmd[i + 1], ">>") == 0 ||
        my_strcmp(cmd[i + 1], ";") == 0 ||
        my_strcmp(cmd[i + 1], "||") == 0 ||
        my_strcmp(cmd[i + 1], "&&") == 0)
            return 1;
    }
    return 0;
}

int verif_pipe(char **cmd, int index, mysh_t *data)
{
    int size = size_of_tab(cmd);

    if (verif_basic(cmd, index) == 1) {
        my_printf("Invalid null command.\n");
        data->exit_code = 1; return 1;
    }
    for (int i = 0; cmd[i] != NULL; i++) {
        if (verif_cmd(cmd, size, i) == 1) {
            my_printf("Invalid null command.\n");
            data->exit_code = 1; return 1;
        }
    }
    if (data->info->separator == true && data->exit_code != 0) {
        data->exit_code = 1; return 1;
    }
    if (data->info->double_pipe == true && data->exit_code == 0) {
        data->exit_code = 1;
        return 1;
    }
    return 0;
}
