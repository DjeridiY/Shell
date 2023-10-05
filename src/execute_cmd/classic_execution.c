/*
** PROJECT, 2022
** Shell
** File description:
** classic_execution.c
*/

#include "my.h"
#include "mysh.h"
#include <unistd.h>
#include <stdlib.h>

void classic_execution(mysh_t *data)
{
    int indic = 0;

    find_the_correct_path(data);
    if (cmd_detector_main(data) == 1) {
        indic = 1;
    }
    native_binary_process(data, indic);
}
