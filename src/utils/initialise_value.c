/*
** PROJECT, 2022
** Shell
** File description:
** initialise_value.c
*/

#include "my.h"
#include "mysh.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

void initialise_value(mysh_t *data)
{
    data->cmd = NULL;
    data->raw_cmd = NULL;
    data->new_env = NULL;
    data->prev_dir = NULL;
    data->home_dir = NULL;
    data->path = NULL;
    data->pwd = NULL;
    data->size_of_tab = 0;
    data->recup = 0;
    data->error_msg = 0;
    data->exit_code = 0;
    data->free_path = 0;
    data->complex = false;
    data->history = malloc(sizeof(list_t *));
    *data->history = NULL;
}
