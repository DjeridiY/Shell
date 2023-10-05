/*
** EPITECH PROJECT, 2023
** Shell
** File description:
** create_history
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "my.h"
#include "mysh.h"
#include "list.h"

static char *get_current_time(void)
{
    char *str_time = NULL;
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    str_time = malloc(sizeof(char) * 6);
    if (str_time == NULL) {
        return NULL;
    }
    sprintf(str_time, "%02d:%02d", tm.tm_hour, tm.tm_min);
    return str_time;
}

static int create_history_data(list_t *node, char *cmd_raw)
{
    history_t *history = NULL;
    char *cmd_raw_dup = NULL;

    node->data = malloc(sizeof(history_t));
    if (node->data == NULL) {
        free(node);
        return 1;
    }
    if ((cmd_raw_dup = my_strdup(cmd_raw)) == NULL) {
        free(node->data);
        free(node);
        return 1;
    }
    history = node->data;
    history->cmd = cmd_raw_dup;
    history->date = get_current_time();
    node->next = NULL;
    return 0;
}

list_t *create_history(char *cmd_raw)
{
    list_t *node = malloc(sizeof(list_t));

    if (node == NULL) {
        return NULL;
    }
    if (create_history_data(node, cmd_raw) == 1) {
        return NULL;
    }
    return node;
}
