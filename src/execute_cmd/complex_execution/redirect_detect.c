/*
** PROJECT, 2022
** Shell
** File description:
** redirect_detect.c
*/

#include "my.h"
#include "mysh.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

int redirect_detect(mysh_t *data, complex_t *info, int *i)
{
    if (info->redirect_output) {
        info->redirect_output = redirect_output_save(data, info, (*i));
        (*i)++;
        return 1;
    }
    if (my_strcmp(data->cmd[(*i)], ">") == 0) {
        (*i)++;
        return 2;
    }
    if (my_strcmp(data->cmd[(*i)], "<") == 0) {
        info->redirect_in = true;
        (*i)++;
        return 2;
    }
    if (my_strcmp(data->cmd[(*i)], ">>") == 0) {
        info->double_out = true;
        (*i)++;
        return 2;
    }
    return 0;
}
