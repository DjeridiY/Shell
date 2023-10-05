/*
** PROJECT, 2022
** Shell
** File description:
** my_unsetenv.c
*/

#include "my.h"
#include "mysh.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

void moove_to_the_right(mysh_t *data, int i, int j)
{
    for (j = i; data->new_env[j] != NULL; j++) {
        data->new_env[j] = data->new_env[j + 1];
    }
}

int my_unsetenv(mysh_t *data)
{
    int i = 0;
    int j = 0;
    int len = 0;

    if (size_of_tab(data->info->av) != 2) {
        error("unsetenv: Too few arguments.\n");
        return 1;
    }
    len = my_strlen(data->info->av[1]);
    for (i = 0; data->new_env[i] != NULL; i++) {
        if (my_strncmp(data->info->av[1], data->new_env[i], len) == 0
        && data->new_env[i][len] == '=') {
            free(data->new_env[i]);
            moove_to_the_right(data, i, j);
            return 0;
        }
    }
    return -1;
}
