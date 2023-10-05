/*
** PROJECT, 2022
** Shell
** File description:
** double_pipe_execute.c
*/

#include "my.h"
#include "mysh.h"
#include <stdlib.h>
#include <stdbool.h>

void finish_double_pipe(mysh_t *data, complex_t *info, char *temp)
{
    free(data->raw_cmd);
    data->raw_cmd = my_strdup(temp);
    free(temp);
    free_tab(info->av);
    free(info->output_file);
    info->av = malloc(sizeof(char *) * (size_of_tab(data->cmd) + 1));
    info->status = false;
    info->double_pipe = true;
}

void error_execute(mysh_t *data, complex_t *info, char *raw_cmd)
{
    if (data->exit_code != 0) {
        if (cmd_detector_main(data) != 1)
            data->exit_code = simple_execution(data, info, raw_cmd);
    }
}

void choose_double_pipe_exe(mysh_t *data, complex_t *info, char *raw_cmd)
{
    if (info->double_pipe == true) {
        error_execute(data, info, raw_cmd);
    } else {
        if (cmd_detector_main(data) != 1)
            data->exit_code = simple_execution(data, info, raw_cmd);
    }
}

void double_pipe_execute(mysh_t *data, complex_t *info, int i)
{
    char *raw_cmd = NULL;
    char *temp = NULL;

    data->info->av[data->info->ac] = NULL;
    if (info->ac != 0) {
        raw_cmd = my_strdup(info->av[0]);
        info->ac = 0;
        complex_path(data->info->av, data->path, data->pwd);
        temp = my_strdup(data->raw_cmd);
        free(data->raw_cmd);
        data->raw_cmd = my_strdup(raw_cmd);
        choose_double_pipe_exe(data, info, raw_cmd);
        finish_double_pipe(data, info, temp);
    }
    free(raw_cmd);
    if (data->exit_code != 0) {
        complex_execution(data, info, i + 1);
    }
}
