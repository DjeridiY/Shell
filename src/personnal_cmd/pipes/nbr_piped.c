/*
** PROJECT, 2022
** B-PSU-200-PAR-2-1-minishell2-yanis.djeridi
** File description:
** nbr_piped.c
*/

#include "my.h"
#include "mysh.h"
#include <unistd.h>
#include <stdlib.h>

int nbr_piped(char **cmd, int i, complex_t *info)
{
    int cmd_piped = 2;
    int index = 0;

    i += 1;
    while (cmd[i] != NULL) {
        if (my_strcmp(cmd[i], "|") == 0) {
            cmd_piped++;
        }
        if (my_strcmp(cmd[i], ">") == 0 ||
        my_strcmp(cmd[i], "<") == 0 || my_strcmp(cmd[i], ">>") == 0
        || my_strcmp(cmd[i], ";") == 0 || my_strcmp(cmd[i], "||") == 0
        || my_strcmp(cmd[i], "&&") == 0)
            break;
        index++;
        i++;
    }
    info->skip = index;
    return cmd_piped;
}
