/*
** PROJECT, 2022
** Shell
** File description:
** signal_handler.c
*/

#include "my.h"
#include "mysh.h"
#include <signal.h>

void sigint_handler(int signum)
{
    my_putchar('\n');
    signal(SIGINT, SIG_DFL);
    signum = signum;
}
