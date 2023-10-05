/*
** PROJECT, 2022
** Shell
** File description:
** free_new_path.c
*/

#include "my.h"
#include "mysh.h"
#include <stdlib.h>

void reset_cmd(mysh_t *data, char *temp_cmd, char **temp_tab)
{
    free(data->raw_cmd);
    free_tab(data->cmd);
    data->raw_cmd = my_strdup(temp_cmd);
    data->cmd = my_tabdup(temp_tab);
    free(temp_cmd);
    free_tab(temp_tab);
}

void cmdcwd_execute(mysh_t *data)
{
    char *cmd = my_getenv(data->new_env, "PRECMD");
    char *temp_cmd = my_strdup(data->raw_cmd);
    char **temp_tab = my_tabdup(data->cmd);

    if (my_strcmp(cmd, "NULL") == 0) {
        free_tab(temp_tab);
        free(temp_cmd);
        free(cmd);
        return;
    }
    free(data->raw_cmd);
    free_tab(data->cmd);
    data->raw_cmd = my_strdup(cmd);
    data->cmd = my_str_to_word_array(cmd, ' ');
    free(cmd);
    classic_execution(data);
    reset_cmd(data, temp_cmd, temp_tab);
}

int free_new_path(mysh_t *data, char *path)
{
    cmdcwd_execute(data);
    if (data->free_path == 1) {
        free(path);
        data->free_path = 0;
        return 0;
    }
    if (data->free_path == 1) {
        free(path);
        free(data->home_dir);
        data->free_path = 0;
        return 0;
    }
    return 0;
}
