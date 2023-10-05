/*
** PROJECT, 2022
** Librairy
** File description:
** my_strdup_array_of_string.c
*/

#include "my.h"
#include "mysh.h"
#include <stdlib.h>
#include <string.h>

char **my_tabdup(char **array)
{
    int size = size_of_tab(array);
    char **tab = malloc(sizeof(char *) * (size + 1));
    int i = 0;

    while (i < size) {
        tab[i] = my_strdup(array[i]);
        i++;
    }
    tab[i] = NULL;
    return tab;
}
