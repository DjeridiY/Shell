/*
** PROJECT, 2022
** Shell
** File description:
** my_getenv.c
*/

#include "my.h"
#include "mysh.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

char *my_getenv(char **env, char *name)
{
    int i = 0;
    char *env_string = NULL;

    while (env[i] != NULL) {
        if (my_strncmp(name, env[i], my_strlen(name)) == 0
        && env[i][my_strlen(name)] == '=') {
            env_string = my_strdup(env[i] + my_strlen(name) + 1);
            break;
        }
        i++;
    }
    return env_string;
}
