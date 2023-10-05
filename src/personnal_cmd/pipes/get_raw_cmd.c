/*
** PROJECT, 2022
** B-PSU-200-PAR-2-1-minishell2-yanis.djeridi
** File description:
** get_raw_cmd.c
*/

#include "mysh.h"
#include "my.h"
#include <stdlib.h>

char **get_raw_cmd(int cmd_piped, char ***cmd)
{
    char **raw = malloc(sizeof(char *) * (cmd_piped + 1));

    for (int i = 0; i < cmd_piped; i++) {
        raw[i] = my_strdup(cmd[i][0]);
    }
    raw[cmd_piped] = NULL;
    return raw;
}
