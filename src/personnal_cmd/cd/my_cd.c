/*
** PROJECT, 2022
** Shell
** File description:
** my_cd.c
*/

#include "my.h"
#include "mysh.h"
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <errno.h>
#include <sys/stat.h>

int basic_error(char *path, int size)
{
    struct stat sb;
    if (stat(path, &sb) == -1)
        return 0;
    if ((S_ISDIR(sb.st_mode)) == false) {
        error(path);
        error(": Not a directory.\n");
        return 1;
    }
    if (size > 2) {
        error("cd: Too many arguments.\n");
        return 1;
    }
    return 0;
}

void error_chdir(char *path)
{
    error(path);
    if (errno == EACCES) {
        error(": permission denied.\n");
    }
    if (errno == ENOENT) {
        error(": no such file or directory.\n");
    }
    if (errno == EEXIST) {
        error(": not a directory.\n");
    }
}

int my_cd(mysh_t *data)
{
    char **args = data->info->av;
    char *path = args[1];

    if (basic_error(path, size_of_tab(data->info->av)) == 1)
        return 1;
    path = choose_cd(data, path);
    if (path == 0)
        return 0;
    free(data->prev_dir);
    data->prev_dir = getcwd(NULL, 0);
    if (data->prev_dir == NULL) {
        error("error: can't get current directory\n");
        return 1;
    }
    if (chdir(path) == -1) {
        error_chdir(path);
        return 1;
    }
    free_new_path(data, path);
    return 0;
}
