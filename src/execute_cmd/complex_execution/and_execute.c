/*
** PROJECT, 2022
** Shell
** File description:
** and_execute.c
*/

#include "my.h"
#include "mysh.h"
#include <stdlib.h>
#include <stdbool.h>

void finish_and_execution(mysh_t *data, complex_t *info, char *temp)
{
    free(data->raw_cmd);
    data->raw_cmd = my_strdup(temp);
    free(temp);
    free_tab(info->av);
    free(info->output_file);
    info->av = malloc(sizeof(char *) * (size_of_tab(data->cmd) + 1));
    info->status = false;
    info->separator = true;

}

void can_pass(mysh_t *data, complex_t *info, char *raw_cmd)
{
    if (data->exit_code == 0) {
        if (cmd_detector_main(data) != 1)
            data->exit_code = simple_execution(data, info, raw_cmd);
    }
}

void and_format(mysh_t *data, complex_t *info, char *raw_cmd)
{
    if (info->separator) {
        can_pass(data, info, raw_cmd);
    } else {
        if (cmd_detector_main(data) != 1)
            data->exit_code = simple_execution(data, info, raw_cmd);
    }
}

void and_execute(mysh_t *data, complex_t *info, int i)
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
        and_format(data, info, raw_cmd);
        finish_and_execution(data, info, temp);
    }
    free(raw_cmd);
    if (data->exit_code == 0) {
        complex_execution(data, info, i + 1);
    }
}
