/*
** PROJECT, 2022
** Shell
** File description:
** main.c
*/

#include "my.h"
#include "mysh.h"
#include <stdlib.h>
#include <signal.h>
#include <stdio.h>

int mysh(mysh_t *data)
{
    signal(SIGINT, sigint_handler);
    data->recup = wait_command(data);
    if (data->recup == 2 || data->recup == 84) {
        return data->recup;
    }
    data->raw_cmd = my_strdup(data->cmd[0]);
    precmd(data);
    complex_main(data);
    free_tab(data->cmd);
    free(data->raw_cmd);
    return data->recup;
}

int main(int ac, char **av, char **env)
{
    mysh_t *data = malloc(sizeof(mysh_t));
    int recup = 0;
    (void)av;

    if (ac != 1)
        return 84;
    initialise_value(data);
    copy_of_env(data, env);
    while (1) {
        if (mysh(data) == 84)
            break;
    }
    recup = data->exit_code;
    free_utils(data);
    return recup;
}
