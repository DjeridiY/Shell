/*
** PROJECT, 2022
** B-PSU-200-PAR-2-1-minishell2-yanis.djeridi
** File description:
** create_pipes.c
*/

#include "my.h"
#include "mysh.h"
#include <unistd.h>
#include <stdlib.h>

int create_pipes(int cmd_piped, int **pipes)
{
    for (int i = 0; i < cmd_piped; i++) {
        if (pipe(pipes[i]) == -1) {
            my_printf("pipe");
            return 84;
        }
    }
    return 0;
}
