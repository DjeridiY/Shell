/*
** PROJECT, 2022
** B-PSU-200-PAR-2-1-minishell2-yanis.djeridi
** File description:
** error_with_cmd.c
*/

#include "my.h"
#include "mysh.h"
#include <unistd.h>
#include <stdlib.h>

void error_with_cmd(int recup, char **raw_cmd, int i)
{
    if (recup == -1) {
        child_error(raw_cmd[i]);
        free_tab(raw_cmd);
        exit(1);
    }
}
