/*
** PROJECT, 2022
** B-PSU-200-PAR-2-1-minishell2-yanis.djeridi
** File description:
** set_data.c
*/

#include "my.h"
#include "mysh.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void set_data(complex_t *info)
{
    info->output_file = NULL;
    info->saved_stdout = dup(STDOUT_FILENO);
}
