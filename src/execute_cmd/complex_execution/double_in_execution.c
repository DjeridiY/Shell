/*
** PROJECT, 2022
** B-PSU-200-PAR-2-1-minishell2-yanis.djeridi
** File description:
** double_in_execution.c
*/

#include "my.h"
#include "mysh.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/types.h>
#include <errno.h>
#include <stdio.h>

void error_with_execution(char *raw_cmd, int recup)
{
    if (recup == -1) {
        child_error(raw_cmd);
        exit(1);
    }
}

void child_in_process(mysh_t *data, int *pipefd)
{
    redirect_pipes(data->info);
    close(pipefd[1]);
    dup2(pipefd[0], STDIN_FILENO);
    close(pipefd[0]);
}

int redirect_data(int *pipefd, char **input, pid_t child_pid, int status)
{
    close(pipefd[0]);
    for (int i = 0; input[i] != NULL; i++)
        write(pipefd[1], input[i], my_strlen(input[i]));
    close(pipefd[1]);
    waitpid(child_pid, &status, 0);
    return status;
}

int double_in_execution(mysh_t *data, char *raw_cmd, char **input, int i)
{
    int *pipefd = malloc(sizeof(int) * 2);
    int status = 0;
    int recup = 0;

    data->info->file = find_file(data, i + 1);
    pipe(pipefd);
    pid_t child_pid = fork();
    if (child_pid == -1) {
        perror("fork");
        exit(1);
    } else if (child_pid == 0) {
        child_in_process(data, pipefd);
        recup = execve(data->info->av[0], data->info->av, data->new_env);
        error_with_execution(raw_cmd, recup);
    } else {
        status = redirect_data(pipefd, input, child_pid, status);
    }
    free(pipefd);
    return status_handler(status);
}
