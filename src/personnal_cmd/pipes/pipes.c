/*
** PROJECT, 2022
** B-PSU-200-PAR-2-1-minishell2-yanis.djeridi
** File description:
** pipes.c
*/

#include "my.h"
#include "mysh.h"
#include <unistd.h>
#include <stdlib.h>

int child_process(int **pipes, int cmd_piped, int i)
{
    close_read_and_write(cmd_piped, pipes, i);
    redirection_std(cmd_piped, pipes, i);
    close_pipes(cmd_piped, pipes, i);
    return 0;
}

void finish_pipe(complex_t *info, int cmd_piped, pid_t *child_pid, mysh_t *data)
{
    destroy_pipes(cmd_piped, info->pipes);
    wait_child(cmd_piped, child_pid, data);
    free_pipes(cmd_piped, info->pipes);
    free_cmd(info->cmd, cmd_piped);
    free_tab(info->raw_cmd);
    free(info->file);
    info->double_out = false;
    info->redirect_in = false;
}

int info_setup(mysh_t *data, complex_t *info, int cmd_piped, int i)
{
    info->cmd = allocate_commands(cmd_piped, data->cmd, i);
    info->raw_cmd = get_raw_cmd(cmd_piped, info->cmd);
    info->pipes = create_pipes_array(cmd_piped);
    info->file = find_file(data, i);
    set_path(info->cmd, data);
    if (create_pipes(cmd_piped, info->pipes) == 84) {
        data->exit_code = 1;
        return 1;
    }
    return 0;
}

int execute_pipe_command(mysh_t *data, complex_t *info, int i)
{
    char *temp_cmd = my_strdup(data->raw_cmd);
    char **temp_tab = my_tabdup(data->cmd);
    int recup = 0;

    free(data->raw_cmd);
    free_tab(data->cmd);
    data->raw_cmd = my_strdup(info->cmd[i][0]);
    data->cmd = my_tabdup(info->cmd[i]);
    if (cmd_detector_main(data) != 1) {
        recup = execve(info->cmd[i][0], info->cmd[i], data->new_env);
    } else {
        recup = data->exit_code;
    }
    free(data->raw_cmd);
    free_tab(data->cmd);
    data->cmd = my_tabdup(temp_tab);
    data->raw_cmd = my_strdup(temp_cmd);
    return recup;
}

void pipes(mysh_t *data, complex_t *info, int i)
{
    int cmd_piped = nbr_piped(data->cmd, i, info);
    pid_t pid;
    pid_t child_pid[cmd_piped]; int recup = 0;

    if (verif_pipe(data->cmd, i, data) == 1)
        return;
    if (info_setup(data, info, cmd_piped, i) == 1)
        return;
    for (int i = 0; i < cmd_piped; ++i) {
        pid = fork();
        if (pid == 0) {
            redirect_pipes(info);
            child_process(info->pipes, cmd_piped, i);
            recup = execute_pipe_command(data, info, i);
            error_with_cmd(recup, info->raw_cmd, i);
        } else {
            child_pid[i] = pid;
        }
    }
    finish_pipe(info, cmd_piped, child_pid, data);
}
