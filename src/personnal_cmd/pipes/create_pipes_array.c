/*
** PROJECT, 2022
** B-PSU-200-PAR-2-1-minishell2-yanis.djeridi
** File description:
** create_pipes_array.c
*/

#include "my.h"
#include "mysh.h"
#include <unistd.h>
#include <stdlib.h>

int **create_pipes_array(int cmd_piped)
{
    int **pipes = malloc(sizeof(int *) * (cmd_piped));

    for (int i = 0; i < cmd_piped; i++) {
        pipes[i] = malloc(sizeof(int) * (2));
    }
    return pipes;
}
