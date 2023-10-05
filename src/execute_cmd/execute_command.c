/*
** PROJECT, 2022
** Shell
** File description:
** execute_command.c
*/

#include "my.h"
#include "mysh.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int execute_command(char **args, char **env, char *raw_cmd)
{
    int child_pid = fork();
    int status = 0;
    int recup = 0;

    if (child_pid > 0) {
        waitpid(child_pid, &status, 0);
    } else if (child_pid == -1) {
        perror("fork");
    } else {
        recup = execve(args[0], args, env);
        if (recup == -1) {
            child_error(raw_cmd);
            exit(1);
        }
    }
    return status_handler(status);
}

void native_binary_process(mysh_t *data, int indic)
{
    if (indic == 0) {
        data->exit_code = execute_command(data->cmd,
        data->new_env, data->raw_cmd);
    }
}
