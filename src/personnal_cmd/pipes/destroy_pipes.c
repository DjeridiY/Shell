/*
** PROJECT, 2022
** B-PSU-200-PAR-2-1-minishell2-yanis.djeridi
** File description:
** destroy_pipes.c
*/

#include "my.h"
#include "mysh.h"
#include <unistd.h>

void destroy_pipes(int cmd_piped, int **pipes)
{
    for (int i = 0; i < cmd_piped; ++i) {
        close(pipes[i][0]);
        close(pipes[i][1]);
    }
}
