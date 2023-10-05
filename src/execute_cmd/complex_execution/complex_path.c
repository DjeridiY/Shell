/*
** PROJECT, 2022
** B-PSU-200-PAR-2-1-minishell2-yanis.djeridi
** File description:
** complex_path.c
*/

#include "my.h"
#include "mysh.h"
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>

char *concat_string_path(char *string, char *tmp, char **tab)
{
    int i = 0;
    int k = 0;

    while (string[i] != '\0') {
        tmp[i] = string[i];
        i++;
    }
    while (tab[0][k] != '\0') {
        tmp[i] = tab[0][k];
        i++;
        k++;
    }
    tmp[i] = '\0';
    return tmp;
}

void concat_path(char *string, char **tab)
{
    int total_len = my_strlen(string) + my_strlen(tab[0]);
    char *tmp = malloc(sizeof(char) * (total_len + 1));

    concat_string_path(string, tmp, tab);
    free(tab[0]);
    tab[0] = my_strdup(tmp);
    free(tmp);
}

char *format_complex_path(char *path)
{
    char *temp = malloc(sizeof(char) * (my_strlen(path) + 2));

    my_strcpy(temp, path);
    my_strcat(temp, "/");
    free(path);
    path = my_strdup(temp);
    free(temp);
    return path;
}

void complex_path(char **tab, char *path, char *pwd)
{
    struct stat sb;
    char **all_path = my_str_to_word_array(path, ':');
    char *raw_cmd = my_strdup(tab[0]);

    all_path = add_tab_line(all_path, pwd);
    for (int i = 0; all_path[i] != NULL; i++) {
        all_path[i] = format_complex_path(all_path[i]);
    }
    for (int i = 0; all_path[i] != NULL; i++) {
        concat_path(all_path[i], tab);
        if (stat(tab[0], &sb) != -1) {
            free_tab(all_path);
            free(raw_cmd);
            return;
        }
        free(tab[0]);
        tab[0] = my_strdup(raw_cmd);
    }
    free_tab(all_path);
    free(raw_cmd);
}
