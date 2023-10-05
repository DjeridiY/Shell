/*
** PROJECT, 2022
** B-PSU-200-PAR-2-1-minishell2-yanis.djeridi
** File description:
** free_array_of_array.c
*/

#include <stddef.h>
#include <stdlib.h>
#include "mysh.h"

void free_cmd(char ***cmd, int cmd_piped)
{
    for (int i = 0; i < cmd_piped; i++) {
        for (int j = 0; cmd[i][j] != NULL; j++) {
            free(cmd[i][j]);
        }
        free(cmd[i]);
    }
    free(cmd);
}
