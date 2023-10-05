/*
** PROJECT, 2022
** Shell
** File description:
** find_the_correct_path.c
*/

#include "my.h"
#include "mysh.h"
#include <stdlib.h>
#include <sys/stat.h>

int find_the_correct_path(mysh_t *data)
{
    struct stat sb;
    char **all_path = my_str_to_word_array(data->path, ':');

    all_path = add_tab_line(all_path, data->pwd);
    for (int i = 0; all_path[i] != NULL; i++) {
        all_path[i] = format_path(all_path[i]);
    }
    for (int i = 0; all_path[i] != NULL; i++) {
        concat(data, all_path[i]);
        if (stat(data->cmd[0], &sb) != -1) {
            free_tab(all_path);
            return 0;
        }
        free(data->cmd[0]);
        data->cmd[0] = my_strdup(data->raw_cmd);
    }
    free_tab(all_path);
    return 1;
}
