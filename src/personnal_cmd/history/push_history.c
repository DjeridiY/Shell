/*
** PROJECT, 2022
** Shell
** File description:
** push_history.c
*/

#include <stdio.h>
#include "list.h"
#include "mysh.h"
#include "my.h"

void push_history(list_t **head, char *cmd_raw)
{
    list_t *node = NULL;

    node = create_history(cmd_raw);
    if (node == NULL) {
        return;
    }
    if (*head == NULL) {
        *head = node;
        return;
    }
    list_t *temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = node;
}
