/*
** PROJECT, 2022
** Shell
** File description:
** my_env.c
*/

#include "mysh.h"
#include "my.h"

int my_env(mysh_t *data)
{
    print_tab(data->new_env);
    return 0;
}
