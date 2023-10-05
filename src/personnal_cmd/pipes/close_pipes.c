/*
** PROJECT, 2022
** B-PSU-200-PAR-2-1-minishell2-yanis.djeridi
** File description:
** close_pipes.c
*/

#include "my.h"
#include "mysh.h"
#include <unistd.h>

void close_pipes(int cmd_piped, int **pipes, int i)
{
    for (int j = 0; j < cmd_piped; j++) {
        if (j != i && j != i + 1) {
            close(pipes[j][0]);
            close(pipes[j][1]);
        }
    }
}
