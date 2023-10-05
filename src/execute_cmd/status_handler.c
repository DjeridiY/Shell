/*
** PROJECT, 2022
** Shell
** File description:
** status_handler.c
*/

#include "my.h"
#include "mysh.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdbool.h>
#include <fcntl.h>
#include <signal.h>

int core_dump_handler(int status)
{
    if (WTERMSIG(status) == SIGSEGV) {
        error("Segmentation fault (core dumped)\n");
        return 139;
    }
    if (WTERMSIG(status) == SIGFPE) {
        error("Floating exception\n");
        return 136;
    }
    if (WTERMSIG(status) == SIGABRT) {
        error("Aborted (core dumped)\n");
        return 134;
    }
    return 0;
}

int term_signal_handler(int status)
{
    if (WTERMSIG(status) == SIGSEGV) {
        error("Segmentation fault\n");
        return 139;
    }
    if (WTERMSIG(status) == SIGFPE) {
        error("Floating exception\n");
        return 136;
    }
    if (WTERMSIG(status) == SIGABRT) {
        error("Aborted\n");
        return 134;
    }
    return 0;
}

int status_handler(int status)
{
    int exit_status = 0;

    if (WCOREDUMP(status)) {
        return core_dump_handler(status);
    } else if (WIFSIGNALED(status)) {
        return term_signal_handler(status);
    }
    if (WIFEXITED(status)) {
        exit_status = WEXITSTATUS(status);
        return exit_status;
    }
    return 0;
}
