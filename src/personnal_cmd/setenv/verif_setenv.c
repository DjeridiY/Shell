/*
** PROJECT, 2022
** Shell
** File description:
** verif_sentence.c
*/

#include "my.h"
#include "mysh.h"
#include <stdlib.h>
#include <stdbool.h>

int find_equal(mysh_t *data)
{
    int equal = 0;

    for (int i = 0; data->info->av[1][i] != '\0'; i++) {
        if (data->info->av[1][i] == '=') {
            equal = 1;
        }
    }
    return equal;
}

void format_string(mysh_t *data)
{
    int equal = 0;
    char *temp = 0;
    int len = my_strlen(data->info->av[1]);
    int j = 0;

    equal = find_equal(data);
    if (equal == 0) {
        temp = my_strdup(data->info->av[1]);
        free(data->info->av[1]);
        data->info->av[1] = malloc(sizeof(char) * (len + 2));
        while (temp[j] != '\0') {
            data->info->av[1][j] = temp[j];
            j++;
        }
        data->info->av[1][j] = '=';
        j++;
        data->info->av[1][j] = '\0';
        free(temp);
    }
}

void verif_string(mysh_t *data)
{
    int len_1 = my_strlen(data->info->av[1]);
    int len_2 = my_strlen(data->info->av[2]);
    char *temp = malloc(sizeof(char) * (len_1 + len_2 + 2));

    temp = my_strcpy(temp, data->info->av[1]);
    temp = my_strcat(temp, "=");
    temp = my_strcat(temp, data->info->av[2]);
    free(data->info->av[1]);
    data->info->av[1] = my_strdup(temp);
}

int verif_setenv(mysh_t *data)
{
    if (data->info->av[1] == NULL) {
        my_env(data);
        return 84;
    }
    if (my_str_isalpha(data->info->av[1]) == 1) {
        error("setenv: Variable name must contain alphanumeric characters.\n");
        return 84;
    }
    if (!((data->info->av[1][0] >= 'a' && data->info->av[1][0] <= 'z') ||
    (data->info->av[1][0] >= 'A' && data->info->av[1][0] <= 'Z'))) {
        error("setenv: Variable name must begin with a letter.\n");
    }
    if (size_of_tab(data->info->av) == 2) {
        format_string(data);
    }
    if (size_of_tab(data->info->av) == 3) {
        verif_string(data);
    }
    return 0;
}
