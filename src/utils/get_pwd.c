/*
** PROJECT, 2022
** Shell
** File description:
** get_pwd.c
*/

#include "my.h"
#include "mysh.h"
#include <stdlib.h>
#include <stdio.h>

char *get_pwd(char **env, char *path)
{
    char *pwd = NULL;

    pwd = my_getenv(env, "PWD");
    if (pwd == NULL) {
        pwd = my_strdup(path);
    }
    return pwd;
}
