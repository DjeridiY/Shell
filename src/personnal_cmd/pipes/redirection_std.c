/*
** PROJECT, 2022
** B-PSU-200-PAR-2-1-minishell2-yanis.djeridi
** File description:
** redirection_std.c
*/

#include "my.h"
#include "mysh.h"
#include <signal.h>
#include <unistd.h>

void redirection_std(int cmd_piped, int **pipes, int i)
{
    if (i != 0) {
        dup2(pipes[i - 1][0], STDIN_FILENO);
    }
    if (i != cmd_piped - 1) {
        dup2(pipes[i][1], STDOUT_FILENO);
    }
}
