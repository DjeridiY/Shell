/*
** EPITECH PROJECT, 2023
** Shell
** File description:
** stdin_events
*/

#include "mysh.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void refresh_line(char *line, int idx, int len)
{
    printf("\033[2K\r\033[1;33m└─$\033[0m %s", line);
    for (int i = idx; i < len; i++) {
        printf("\033[D");
    }
}

static void process_backspace(char **line, int *idx, size_t *len)
{
    if ((*idx) > 0) {
        for (int i = (*idx) - 1; i < (int)(*len) - 1; i++) {
            (*line)[i] = (*line)[i + 1];
        }
        (*idx)--;
        (*len)--;
        (*line)[*len] = '\0';
        refresh_line(*line, *idx, *len);
    }
}

static void insert_char(char **line, char ch, int *idx, size_t *len)
{
    (*line) = realloc((*line), ++(*len) + 2);
    if (ch == '\n') {
        (*line)[(*len) - 1] = '\n';
        (*idx) = (*len);
        refresh_line(*line, *idx, *len);
        return;
    }
    for (int i = (*len) - 1; i > (*idx); i--)
        (*line)[i] = (*line)[i - 1];
    (*line)[(*idx)++] = ch;
    (*line)[(*len)] = '\0';
    memset((*line) + (*len) + 1, 0, 1);
    refresh_line(*line, *idx, *len);
}

static void input_offset(char ch, int *idx, size_t len)
{
    if (ch == 'C' && (*idx) < (int)len) {
        (*idx)++;
        printf("\033[C");
    } else if (ch == 'D' && (*idx) > 0) {
        (*idx)--;
        printf("\033[D");
    }
}

int check_events(char **line, char ch, int *idx, size_t *len)
{
    if (ch == 27) {
        getchar();
        ch = getchar();
        input_offset(ch, idx, (*len));
        return 1;
    }
    if (ch == '\n') {
        insert_char(line, ch, idx, len);
        return 0;
    }
    if (ch == 127) {
        process_backspace(line, idx, len);
    } else {
        insert_char(line, ch, idx, len);
    }
    if (ch == 4)
        return 0;
    return 1;
}
