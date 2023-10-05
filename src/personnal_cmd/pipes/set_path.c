/*
** PROJECT, 2022
** Shell
** File description:
** set_path.c
*/

#include "my.h"
#include "mysh.h"
#include <unistd.h>
#include <stdlib.h>

void set_path(char ***cmd, mysh_t *data)
{
    for (int i = 0; cmd[i] != NULL; i++) {
        complex_path(cmd[i], data->path, data->pwd);
    }
}
