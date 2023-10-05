/*
** PROJECT, 2022
** Shell
** File description:
** copy_of_env.c
*/

#include "my.h"
#include "mysh.h"
#include <string.h>
#include <stdlib.h>

void prompt_command(mysh_t *data)
{
    char *cmd = my_getenv(data->new_env, "PROMPT_COMMAND");
    if (my_strcmp(cmd, "NULL") == 0) {
        free(cmd);
        return;
    }
    data->raw_cmd = my_strdup(cmd);
    data->cmd = my_str_to_word_array(cmd, ' ');
    free(cmd);
    complex_main(data);
    free(data->raw_cmd);
    free_tab(data->cmd);
}

void copy_of_env(mysh_t *data, char **env)
{
    int size = 0;
    int j = 0;

    while (env[size] != NULL) {
        size++;
    }
    data->new_env = malloc(sizeof(char *) * (size + 1));
    while (j < size) {
        data->new_env[j] = my_strdup(env[j]);
        j++;
    }
    data->new_env[j] = NULL;
    data->path = get_path(data->new_env);
    data->pwd = get_pwd(data->new_env, data->path);
    special_variables_set(data);
    prompt_command(data);
}
