/*
** PROJECT, 2022
** B-PSU-200-PAR-2-1-minishell2-yanis.djeridi
** File description:
** close_read_and_write.c
*/

#include "my.h"
#include "mysh.h"
#include <unistd.h>

void close_read_and_write(int cmd_piped, int **pipes, int i)
{
    for (int j = 0; j < i; j++) {
        close(pipes[j][1]);
    }
    for (int j = i + 1; j < cmd_piped; j++) {
        close(pipes[j][0]);
    }
}
