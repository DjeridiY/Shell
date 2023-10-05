/*
** PROJECT, 2022
** Shell
** File description:
** execute_handler.c
*/

#include "my.h"
#include "mysh.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>

void execute_handler(mysh_t *data, char *raw_cmd)
{
    if (data->info->separator == false && data->info->double_pipe == false) {
        data->exit_code = simple_execution(data, data->info, raw_cmd);
    }
    if (data->info->separator == true) {
        if (data->exit_code == 0) {
            data->exit_code = simple_execution(data, data->info, raw_cmd);
        }
    }
    if (data->info->double_pipe == true) {
        if (data->exit_code != 0) {
            data->exit_code = simple_execution(data, data->info, raw_cmd);
        }
    }
}
