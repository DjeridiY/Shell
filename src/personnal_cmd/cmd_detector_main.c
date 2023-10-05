/*
** PROJECT, 2022
** Shell
** File description:
** cmd_detector_main.c
*/

#include "my.h"
#include "mysh.h"
#include "cmd_detector.h"
#include <unistd.h>

void exit_code(mysh_t *data)
{
    if (data->exit_code == 22) {
        data->exit_code = 0;
        data->recup = 84;
    }
}

int cmd_detector_main(mysh_t *data)
{
    for (int i = 0; i < 7; i++) {
        if (my_strcmp(command[i].cmd, data->raw_cmd) == 0) {
            data->exit_code = command[i].detect(data);
            exit_code(data);
            return 1;
        }
    }
    for (int i = 0; i < 6; i++) {
        if (my_strncmp(command[i].cmd, data->raw_cmd,
        my_strlen(command[i].cmd)) == 0) {
            data->exit_code = command[i].detect(data);
            exit_code(data);
            return 1;
        }
    }
    return 0;
}
