/*
** PROJECT, 2022
** Shell
** File description:
** get_command.c
*/

#include "my.h"
#include "mysh.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <termios.h>

static void init_term(struct termios *old_term, struct termios *new_term)
{
    tcgetattr(STDIN_FILENO, old_term);
    *new_term = *old_term;
    new_term->c_lflag &= ~(ICANON | ECHO);
    new_term->c_cc[VMIN] = 1;
    new_term->c_cc[VTIME] = 0;
    tcsetattr(STDIN_FILENO, TCSANOW, new_term);
}

static void reset_term(struct termios *old_term)
{
    tcsetattr(STDIN_FILENO, TCSANOW, old_term);
}

int get_command(mysh_t *data)
{
    struct termios old_term, new_term;
    char ch;
    int idx = 0;
    size_t len = 0;
    char *line = calloc(len + 2, sizeof(char));

    init_term(&old_term, &new_term);
    ch = getchar();
    while (check_events(&line, ch, &idx, &len))
    {
        ch = getchar();
    }
    reset_term(&old_term);
    if (ch == 4)
    {
        free(line);
        return 84;
    }
    return end_command(data, line, len);
}

int get_echo(mysh_t *data)
{
    char *line = NULL;
    size_t len = 0;

    if (getline(&line, &len, stdin) == -1)
    {
        free(line);
        return 84;
    }
    if (line[0] == '\n')
    {
        free(line);
        return 2;
    }
    remove_char(line, '\n');
    for (int i = 0; i < my_strlen(line); i++)
    {
        if (line[i] == '\t')
        {
            line[i] = ' ';
        }
    }
    copying(data, line);
    free(line);
    return 0;
}

int wait_command(mysh_t *data)
{
    int recup = 0;

    if (isatty(STDIN_FILENO) == 1)
    {
        my_printf("\033[1;33m┌──[\033[1;34mDJERIDIY㉿SHELL\033[1;33m]\n"
                  "└─$\033[0m ");
        recup = get_command(data);
    }
    else
    {
        recup = get_echo(data);
    }
    return recup;
}
