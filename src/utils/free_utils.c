/*
** PROJECT, 2022
** Shell
** File description:
** free_utils.c
*/

#include "my.h"
#include "mysh.h"
#include <unistd.h>
#include <stdlib.h>

void free_utils(mysh_t *data)
{
    if (data->prev_dir != NULL)
        free(data->prev_dir);
    free_history(data->history);
    free_tab(data->new_env);
    free(data->pwd);
    free(data->path);
    free(data);
}
