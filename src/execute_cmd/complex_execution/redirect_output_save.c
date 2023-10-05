/*
** PROJECT, 2022
** B-PSU-200-PAR-2-1-minishell2-yanis.djeridi
** File description:
** redirect_output_save.c
*/

#include "my.h"
#include "mysh.h"
#include <stdbool.h>

bool redirect_output_save(mysh_t *data, complex_t *info, int i)
{
    info->output_file = my_strdup(data->cmd[i]);
    return false;
}
