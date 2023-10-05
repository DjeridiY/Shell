/*
** PROJECT, 2022
** Shell
** File description:
** error.c
*/

#include "my.h"
#include "mysh.h"
#include <unistd.h>

void error(char *str)
{
    write(2, str, my_strlen(str));
}
