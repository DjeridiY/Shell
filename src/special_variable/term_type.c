/*
** PROJECT, 2022
** Shell
** File description:
** term_type.c
*/

#include "my.h"
#include "mysh.h"
#include <ncurses.h>
#include <stdlib.h>

void term_type(mysh_t *data)
{
    char *term = NULL;

    initscr();
    term = termname();
    if (term != NULL) {
        unix_setenv("TERM=", term, data);
        free(term);
    }
    endwin();
}
