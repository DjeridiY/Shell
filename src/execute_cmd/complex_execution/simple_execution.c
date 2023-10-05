/*
** PROJECT, 2022
** B-PSU-200-PAR-2-1-minishell2-yanis.djeridi
** File description:
** simple_execution.c
*/

#include "my.h"
#include "mysh.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>

int double_out(complex_t *info)
{
    int fd_out = 0;

    if (info->double_out) {
        fd_out = open(info->output_file, O_CREAT | O_WRONLY
        | O_APPEND, S_IRUSR | S_IWUSR);
        dup2(fd_out, STDOUT_FILENO);
        close(fd_out);
        free(info->output_file);
        info->output_file = NULL;
        return 1;
    }
    return 0;
}

int redirect_in(complex_t *info)
{
    int fd_in = 0;

    if (info->redirect_in) {
        fd_in = open(info->output_file, O_RDONLY);
        dup2(fd_in, STDIN_FILENO);
        close(fd_in);
        free(info->output_file);
        info->output_file = NULL;
        return 1;
    }
    return 0;
}

void redirect_out(complex_t *info)
{
    int fd_out = 0;

    fd_out = open(info->output_file, O_CREAT | O_WRONLY
    | O_TRUNC, S_IRUSR | S_IWUSR);
    dup2(fd_out, STDOUT_FILENO);
    close(fd_out);
    free(info->output_file);
    info->output_file = NULL;
}

void redirect_file(complex_t *info)
{
    int status1 = 0;
    int status2 = 0;

    if (info->output_file != NULL) {
        status1 = double_out(info);
        status2 = redirect_in(info);
        if (status1 == 0 && status2 == 0)
            redirect_out(info);
    }
}

int simple_execution(mysh_t *data, complex_t *info, char *raw_cmd)
{
    int status = 0;
    int recup = 0;
    pid_t child_pid;

    child_pid = fork();
    if (child_pid > 0) {
        waitpid(child_pid, &status, 0);
    } else if (child_pid == -1) {
        perror("fork");
    } else {
        redirect_file(info);
        recup = execve(info->av[0], info->av, data->new_env);
        if (recup == -1) {
            child_error(raw_cmd);
            exit(1);
        }
    }
    info->double_out = false;
    info->redirect_in = false;
    return status_handler(status);
}
