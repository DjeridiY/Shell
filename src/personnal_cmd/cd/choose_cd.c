/*
** PROJECT, 2022
** Shell
** File description:
** choose_cd.c
*/

#include "my.h"
#include "mysh.h"
#include <stdlib.h>
#include <stdio.h>

char *cd_wave(mysh_t *data, char *path)
{
    data->home_dir = my_getenv(data->new_env, "HOME");
    path = my_strcat(data->home_dir, path + 1);
    data->free_path = 1;
    return path;
}

char *choose_cd(mysh_t *data, char *path)
{
    if (path == NULL) {
        data->home_dir = my_getenv(data->new_env, "HOME");
        if (data->home_dir == NULL) {
            error("cd: No $HOME variable set.\n");
            return 0;
        }
        path = data->home_dir;
        data->free_path = 1;
    }
    if (my_strcmp(path, "-") == 0) {
        if (data->prev_dir == NULL) {
            error(": No such file or directory.\n");
            return 0;
        }
        path = my_strdup(data->prev_dir);
        data->free_path = 1;
    } else if (path[0] == '~') {
        path = cd_wave(data, path);
    }
    return path;
}
