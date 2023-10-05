/*
** PROJECT, 2022
** Shell
** File description:
** add_line.c
*/

#include "my.h"
#include "mysh.h"
#include <stdlib.h>
#include <stdio.h>

char **add_tab_line(char **tab, char *string)
{
    int size = size_of_tab(tab);
    char **temp;
    int j = 0;

    temp = malloc(sizeof(char *) * (size + 2));
    while (j < size) {
        temp[j] = my_strdup(tab[j]);
        j++;
    }
    temp[j] = my_strdup(string);
    temp[j + 1] = NULL;
    free_tab(tab);
    return temp;
}
