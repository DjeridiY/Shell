/*
** PROJECT, 2022
** Shell
** File description:
** format_path.c
*/

#include "my.h"
#include "mysh.h"
#include <stdlib.h>

char *format_path(char *path)
{
    char *temp = malloc(sizeof(char) * (my_strlen(path) + 2));

    my_strcpy(temp, path);
    my_strcat(temp, "/");
    free(path);
    path = my_strdup(temp);
    free(temp);
    return path;
}
