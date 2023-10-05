/*
** PROJECT, 2022
** Shell
** File description:
** cmd_detector.h
*/

#include "mysh.h"
#include <stdio.h>
#include <string.h>

#ifndef CMD_DETECTOR_H_
    #define CMD_DETECTOR_H_

typedef struct cmd_detector {
    char *cmd;
    int (*detect)(mysh_t *);
} cmd_detector_t;

cmd_detector_t command[] = {
    {"setenv", &my_setenv},
    {"unsetenv", &my_unsetenv},
    {"env", &my_env},
    {"cd", &my_cd},
    {"history", &my_history},
    {"!", &my_previous_command},
    {"exit", &my_exit}
};

#endif /* CMD_DETECTOR_H_ */
