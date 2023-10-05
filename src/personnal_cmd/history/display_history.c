/*
** PROJECT, 2022
** Shell
** File description:
** display_history.c
*/

#include <stdio.h>
#include "list.h"
#include "my.h"
#include "mysh.h"

void display_history(mysh_t *mysh)
{
    list_t *temp = *(mysh->history);
    history_t *history = NULL;
    int i = 1;

    while (temp != NULL) {
        history = (history_t *)temp->data;
        printf(" %d  %s   %s\n", i, history->date, history->cmd);
        temp = temp->next;
        i++;
    }
}
