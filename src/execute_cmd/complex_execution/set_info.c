/*
** PROJECT, 2022
** Shell
** File description:
** set_info.c
*/

#include "my.h"
#include "mysh.h"
#include <stdlib.h>

void set_info(mysh_t *data)
{
    data->info = malloc(sizeof(complex_t));
    data->info->av = malloc(sizeof(char *) * (size_of_tab(data->cmd) + 1));
    data->info->ac = 0;
    data->info->status = false;
    data->info->double_out = false;
    data->info->redirect_in = false;
    data->info->separator = false;
    data->info->double_pipe = false;
    data->info->redirect_output = false;
}
