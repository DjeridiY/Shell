/*
** PROJECT, 2022
** Shell
** File description:
** already_exist.c
*/

#include "my.h"
#include "mysh.h"
#include <unistd.h>
#include <stdlib.h>

void already_exist(mysh_t *data)
{
    char *temp = NULL;
    char *copy = my_strdup(data->info->av[1]);

    remove_char(data->info->av[1], '=');
    temp = my_getenv(data->new_env, data->info->av[1]);
    if (temp != NULL) {
        my_unsetenv(data);
    }
    free(data->info->av[1]);
    data->info->av[1] = my_strdup(copy);
    free(temp);
    free(copy);
}
