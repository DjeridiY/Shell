/*
** PROJECT, 2022
** Shell
** File description:
** special_variable.c
*/

#include "my.h"
#include "mysh.h"
#include "ncurses.h"

void special_variables_set(mysh_t *data)
{
    unix_setenv("IGNOREEOF=", "NULL", data);
    unix_setenv("CWDCMD=", "NULL", data);
    unix_setenv("PRECMD=", "NULL", data);
    unix_setenv("PROMPT_COMMAND=", "NULL", data);
}
