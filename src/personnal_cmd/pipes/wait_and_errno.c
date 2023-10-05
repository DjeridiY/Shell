/*
** PROJECT, 2022
** B-PSU-200-PAR-2-1-minishell2-yanis.djeridi
** File description:
** wait_and_errno.c
*/

#include "my.h"
#include "mysh.h"
#include <stdlib.h>

void wait_child(int cmd_piped, pid_t *child_pid, mysh_t *data)
{
    int status = 0;

    for (int i = 0; i < cmd_piped; i++) {
        waitpid(child_pid[i], &status, 0);
    }
    data->exit_code = status_handler(status);
}
