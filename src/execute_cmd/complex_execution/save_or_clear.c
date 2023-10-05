/*
** PROJECT, 2022
** Shell
** File description:
** save_or_clear.c
*/

#include "my.h"
#include "mysh.h"
#include <stdlib.h>
#include <stdbool.h>

void save_or_clear(mysh_t *data, complex_t *info, int i)
{
    if (info->status == false) {
        info->av[info->ac] = my_strdup(data->cmd[i]);
        info->ac++;
    } else {
        info->av[info->ac] = NULL;
        free_tab(info->av);
        info->av = malloc(sizeof(char *) * (size_of_tab(data->cmd) + 1));
        info->ac = 0;
        info->status = false;
    }
}
