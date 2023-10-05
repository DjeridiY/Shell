/*
** PROJECT, 2022
** Shell
** File description:
** my_setenv.c
*/

#include "my.h"
#include "mysh.h"
#include <stdlib.h>
#include <stdio.h>

void recopy_env(int size, char **temp, mysh_t *data)
{
    int j = 0;

    size++;
    while (j < size) {
        data->new_env[j] = my_strdup(temp[j]);
        j++;
    }
    data->new_env[j] = NULL;
    free_tab(temp);
}

int my_setenv(mysh_t *data)
{
    int j = 0;
    char **temp;
    int size = 0;

    if (verif_setenv(data) == 84)
        return 1;
    already_exist(data);
    size = size_of_tab(data->new_env);
    temp = malloc(sizeof(char *) * (size + 2));
    while (j < size) {
        temp[j] = my_strdup(data->new_env[j]);
        j++;
    }
    temp[j] = my_strdup(data->info->av[1]);
    temp[j + 1] = NULL;
    free_tab(data->new_env);
    data->new_env = malloc(sizeof(char *) * (size + 2));
    recopy_env(size, temp, data);
    return 0;
}
