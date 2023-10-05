/*
** PROJECT, 2022
** Shell
** File description:
** free_history.c
*/

#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "mysh.h"

void free_history(list_t **head)
{
    list_t *temp = *head;
    list_t *to_free = NULL;
    history_t *history = NULL;

    if (head == NULL) {
        return;
    }
    while (temp != NULL) {
        to_free = temp;
        temp = temp->next;
        history = (history_t *)to_free->data;
        free(history->cmd);
        free(history->date);
        free(history);
        free(to_free);
    }
    free(head);
}
