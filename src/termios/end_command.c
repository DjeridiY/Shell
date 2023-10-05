/*
** EPITECH PROJECT, 2023
** Shell3
** File description:
** end_command
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "mysh.h"

int end_command(mysh_t *data, char *line, size_t len)
{
    if (len == 0) {
        free(line);
        return 84;
    }
    if (line[0] == '\n') {
        free(line);
        return 2;
    }
    remove_char(line, '\n');
    push_history(data->history, line);
    for (size_t i = 0; i < strlen(line); i++) {
        if (line[i] == '\t') {
            line[i] = ' ';
        }
    }
    copying(data, line);
    free(line);
    return 0;
}
