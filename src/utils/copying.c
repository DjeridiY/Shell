/*
** PROJECT, 2022
** Shell
** File description:
** copying.c
*/

#include "my.h"
#include "mysh.h"
#include <stdbool.h>

bool its_complex(char *line)
{
    for (int i = 0; line[i] != '\0'; i++) {
        if (line[i] == '|' || line[i] == '>'
        || line[i] == ';' || line[i] == '<' ||
        (line[i] == '&' && line[i + 1] == '&')) {
            return true;
        }
    }
    return false;
}

void copying(mysh_t *data, char *line)
{
    data->cmd = my_str_to_word_array(line, ' ');
    data->complex = its_complex(line);
}
