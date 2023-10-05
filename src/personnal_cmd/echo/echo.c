/*
** EPITECH PROJECT, 2023
** Shell
** File description:
** echo
*/

#include "my.h"
#include "mysh.h"
#include <string.h>
#include <stdio.h>

static void print_echo(mysh_t *data)
{
    for (int i = 1; data->cmd[i]; i++) {
        printf("%s", data->cmd[i]);
        if (data->cmd[i] != NULL)
            printf(" ");
    }
    printf("\n");
}

int my_echo(mysh_t *data)
{
    if (strcmp(data->cmd[1], "$?") == 0) {
        printf("%d\n", data->exit_code);
        return 0;
    } if (strcmp(data->cmd[1], "-e") == 0 || strcmp(data->cmd[1], "-E") == 0) {
        printf("\n");
        return 0;
    } if (strcmp(data->cmd[1], "-n") == 0) {
        return 0;
    } else {
        print_echo(data);
        return 0;
    }
    return 0;
}
