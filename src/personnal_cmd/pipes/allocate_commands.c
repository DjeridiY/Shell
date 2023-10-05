/*
** PROJECT, 2022
** B-PSU-200-PAR-2-1-minishell2-yanis.djeridi
** File description:
** allocate_commands.c
*/

#include "my.h"
#include "mysh.h"
#include <unistd.h>
#include <stdlib.h>

int put_args(char ***hub, char **cmd, int index, int i)
{
    int j = 0;

    while (cmd[index] != NULL) {
        if (my_strcmp(cmd[index], ";") == 0 ||
        my_strcmp(cmd[index], "&&") == 0 ||
        my_strcmp(cmd[index], "||") == 0 ||
        my_strcmp(cmd[index], ">") == 0 ||
        my_strcmp(cmd[index], "<") == 0 ||
        my_strcmp(cmd[index], ">>") == 0)
            break;
        if (my_strcmp(cmd[index], "|") == 0) {
            index++;
            break;
        }
        hub[i][j] = my_strdup(cmd[index]);
        j++;
        index++;
    }
    return index;
}

void put_string(char ***hub, int cmd_piped, char **cmd, int index)
{
    for (int i = 0; i < cmd_piped; i++) {
        index = put_args(hub, cmd, index, i);
    }
}

int how_many_alloc(char ***hub, char **cmd, int index, int i)
{
    int nbr_args = 0;

    while (cmd[index] != NULL) {
        if (my_strcmp(cmd[index], "|") == 0) {
            index++;
            break;
        }
        if (my_strcmp(cmd[index], ";") == 0 ||
        my_strcmp(cmd[index], "&&") == 0 ||
        my_strcmp(cmd[index], "||") == 0 ||
        my_strcmp(cmd[index], ">") == 0 ||
        my_strcmp(cmd[index], "<") == 0 ||
        my_strcmp(cmd[index], ">>") == 0)
            break;
        nbr_args++;
        index++;
    }
    hub[i] = malloc(sizeof(char *) * (nbr_args + 1));
    hub[i][nbr_args] = NULL;
    return index;
}

void malloc_string(char ***hub, char **cmd, int cmd_piped, int index)
{
    for (int i = 0; i < cmd_piped; i++) {
        index = how_many_alloc(hub, cmd, index, i);
    }
}

char ***allocate_commands(int cmd_piped, char **cmd, int index)
{
    char ***hub = NULL;
    int test = index - 1;
    int buff = 0;

    hub = malloc(sizeof(char **) * (cmd_piped + 1));
    hub[cmd_piped] = NULL;
    while (test != -1) {
        if (my_strcmp(cmd[test], ";") == 0 ||
        my_strcmp(cmd[test], "||") == 0 ||
        my_strcmp(cmd[test], "&&") == 0) {
            break;
        }
        test--;
        buff++;
    }
    index = index - buff;
    malloc_string(hub, cmd, cmd_piped, index);
    put_string(hub, cmd_piped, cmd, index);
    return hub;
}
