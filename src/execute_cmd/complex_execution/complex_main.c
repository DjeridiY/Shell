/*
** PROJECT, 2022
** Shell
** File description:
** complex_execution.c
*/

#include "my.h"
#include "mysh.h"
#include <stdlib.h>

void complex_main(mysh_t *data)
{
    char *raw_cmd = NULL;

    set_info(data);
    complex_execution(data, data->info, 0);
    data->info->av[data->info->ac] = NULL;
    if (data->info->av[0] != NULL) {
        data->info->ac = 0;
        raw_cmd = my_strdup(data->info->av[0]);
        complex_path(data->info->av, data->path, data->pwd);
        free(data->raw_cmd);
        data->raw_cmd = my_strdup(raw_cmd);
        if (cmd_detector_main(data) != 1)
            execute_handler(data, raw_cmd);
        free_tab(data->info->av);
        free(raw_cmd);
        free(data->info->output_file);
    } else {
        free(data->info->av);
    }
    free(data->info);
}
