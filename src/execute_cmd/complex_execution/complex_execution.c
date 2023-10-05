/*
** PROJECT, 2022
** B-PSU-200-PAR-2-1-minishell2-yanis.djeridi
** File description:
** complex_execution.c
*/

#include "my.h"
#include "mysh.h"
#include <stdlib.h>
#include <stdbool.h>

bool separator_handling(mysh_t *data, complex_t *info, int i)
{
    if (my_strcmp(data->cmd[i], ";") == 0) {
        semicolon_execute(data, info, i);
        return true;
    }
    if (my_strcmp(data->cmd[i], "&&") == 0) {
        and_execute(data, info, i);
        return true;
    }
    if (my_strcmp(data->cmd[i], "||") == 0) {
        double_pipe_execute(data, info, i);
        return true;
    }
    return false;
}

void complex_execution(mysh_t *data, complex_t *info, int i)
{
    int status = 0;

    set_data(info);
    while (data->cmd[i] != NULL) {
        i = pipe_detect(data, info, i);
        status = redirect_detect(data, info, &i);
        if (status == 2)
            info->redirect_output = true;
        if (status == 1 || status == 2)
            continue;
        if (my_strcmp(data->cmd[i], "<<") == 0) {
            double_in(data, info, &i);
            continue;
        }
        if (separator_handling(data, info, i) == true)
            break;
        save_or_clear(data, info, i);
        i++;
    }
}
