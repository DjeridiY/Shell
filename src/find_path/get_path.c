/*
** PROJECT, 2022
** Shell
** File description:
** get_path.c
*/

#include "my.h"
#include "mysh.h"
#include <unistd.h>
#include <stdlib.h>

char *get_path(char **env)
{
    char *path = NULL;

    path = my_getenv(env, "PATH");
    if (path == NULL) {
        path = malloc(sizeof(char) * (108 + 1));
        my_strcpy(path, "/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:");
        my_strcat(path, "/sbin:/bin:/usr/games:/usr/local/games:");
        my_strcat(path, "/snap/bin:/snap/bin");
    }
    return path;
}
