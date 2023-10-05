/*
** PROJECT, 2022
** Shell
** File description:
** concat.c
*/

#include "my.h"
#include "mysh.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>

char *concat_string(char *string, char *tmp, mysh_t *data)
{
    int i = 0;
    int k = 0;

    while (string[i] != '\0') {
        tmp[i] = string[i];
        i++;
    }
    while (data->cmd[0][k] != '\0') {
        tmp[i] = data->cmd[0][k];
        i++;
        k++;
    }
    tmp[i] = '\0';
    return tmp;
}

void concat(mysh_t *data, char *string)
{
    int total_len = my_strlen(string) + my_strlen(data->cmd[0]);
    char *tmp = malloc(sizeof(char) * (total_len + 1));

    concat_string(string, tmp, data);
    free(data->cmd[0]);
    data->cmd[0] = my_strdup(tmp);
    free(tmp);
    data->size_of_tab = size_of_tab(data->cmd);
}
