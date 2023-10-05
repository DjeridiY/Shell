/*
** PROJECT, 2022
** Shell
** File description:
** child_error.c
*/

#include "my.h"
#include "mysh.h"
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

void child_error(char *raw_cmd)
{
    error(raw_cmd);
    if (errno == ENOEXEC) {
        error(": Exec format error. Wrong Architecture.\n");
        return;
    }
    if (errno == EACCES) {
        error(": Permission denied.\n");
        return;
    }
    error(": Command not found.\n");
}
