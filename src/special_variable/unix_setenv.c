/*
** PROJECT, 2022
** Shell
** File description:
** unix_setenv.c
*/

#include "my.h"
#include "mysh.h"
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

bool replace(mysh_t *data, char *complete, char *name_var)
{
    char *copy = my_strdup(name_var);

    remove_char(copy, '=');
    for (int i = 0; data->new_env[i] != NULL; i++) {
        if (strncmp(copy, data->new_env[i], strlen(copy)) == 0 &&
            data->new_env[i][strlen(copy)] == '=') {
            free(data->new_env[i]);
            free(copy);
            data->new_env[i] = my_strdup(complete);
            free(complete);
            return true;
        }
    }
    free(copy);
    return false;
}

char *concate_two_string(char *str1, char *str2)
{
    int len1 = my_strlen(str1);
    int len2 = my_strlen(str2);
    char *complete = malloc(sizeof(char) * (len1 + len2 + 1));

    complete[0] = '\0';

    my_strcat(complete, str1);
    my_strcat(complete, str2);
    return complete;
}

void unix_setenv(char *variable_name, char *content, mysh_t *data)
{
    int j = 0;
    char **temp;
    int size = 0;
    char *complete = concate_two_string(variable_name, content);

    if (replace(data, complete, variable_name) == true)
        return;
    size = size_of_tab(data->new_env);
    temp = malloc(sizeof(char *) * (size + 2));
    while (j < size) {
        temp[j] = my_strdup(data->new_env[j]);
        j++;
    }
    temp[j] = my_strdup(complete);
    free(complete);
    temp[j + 1] = NULL;
    free_tab(data->new_env);
    data->new_env = malloc(sizeof(char *) * (size + 2));
    recopy_env(size, temp, data);
}
