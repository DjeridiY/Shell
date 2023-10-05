/*
** PROJECT, 2022
** B-PSU-200-PAR-2-1-minishell2-yanis.djeridi
** File description:
** pipe_file.c
*/

#include "my.h"
#include "mysh.h"
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

char *find_file(mysh_t *data, int i)
{
    while (data->cmd[i] != NULL) {
        if (my_strcmp(data->cmd[i], ">") == 0)
            return my_strdup(data->cmd[i + 1]);
        if (my_strcmp(data->cmd[i], "<") == 0) {
            data->info->redirect_in = true;
            return my_strdup(data->cmd[i + 1]);
        }
        if (my_strcmp(data->cmd[i], ">>") == 0) {
            data->info->double_out = true;
            return my_strdup(data->cmd[i + 1]);
        }
        if (my_strcmp(data->cmd[i], ";") == 0)
            return NULL;
        if (my_strcmp(data->cmd[i], "&&") == 0)
            return NULL;
        if (my_strcmp(data->cmd[i], "||") == 0)
            return NULL;
        i++;
    }
    return NULL;
}

int double_pipes_out(complex_t *info)
{
    int fd_out = 0;

    if (info->double_out) {
        fd_out = open(info->file, O_CREAT | O_WRONLY
        | O_APPEND, S_IRUSR | S_IWUSR);
        dup2(fd_out, STDOUT_FILENO);
        close(fd_out);
        free(info->file);
        info->file = NULL;
        return 1;
    }
    return 0;
}

void pipes_out(complex_t *info)
{
    int fd_out = 0;

    fd_out = open(info->file, O_CREAT | O_WRONLY
    | O_TRUNC, S_IRUSR | S_IWUSR);
    dup2(fd_out, STDOUT_FILENO);
    close(fd_out);
    free(info->file);
    info->file = NULL;
}

int pipes_in(complex_t *info)
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

void redirect_pipes(complex_t *info)
{
    int status1 = 0;
    int status2 = 0;

    if (info->file != NULL) {
        status1 = double_pipes_out(info);
        status2 = pipes_in(info);
        if (status1 == 0 && status2 == 0)
            pipes_out(info);
    }
}
