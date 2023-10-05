/*
** PROJECT, 2022
** Shell
** File description:
** d.c
*/

#include "my.h"
#include "mysh.h"
#include <stdlib.h>
#include <stdbool.h>

int pipe_detect(mysh_t *data, complex_t *info, int i)
{
    if (my_strcmp(data->cmd[i], "|") == 0) {
        pipes(data, info, i);
        i += info->skip;
        info->status = true;
    }
    return i;
}
