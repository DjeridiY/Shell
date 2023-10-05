/*
** PROJECT, 2022
** Shell
** File description:
** mysh.h
*/

#include <stdbool.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "my.h"
#include "list.h"

#ifndef MYSH_H_
    #define MYSH_H_

typedef struct history_s {

    char *cmd;
    char *date;

} history_t;

typedef struct complex {

    char ***cmd;
    char **raw_cmd;
    int **pipes;
    char *file;
    char **av;
    int saved_stdout;
    int ac;
    char *output_file;
    int pipes_nbr;
    int skip;
    bool status;
    bool double_out;
    bool redirect_in;
    bool double_pipe;
    bool redirect_output;
    bool separator;

} complex_t;

typedef struct mysh {

    complex_t *info;
    list_t **history;
    char **cmd;
    char *raw_cmd;
    char **new_env;
    char *prev_dir;
    char *home_dir;
    char *path;
    char *pwd;
    int size_of_tab;
    int recup;
    int error_msg;
    int exit_code;
    int free_path;
    bool complex;

} mysh_t;

int main(int ac, char **av, char **env);
int mysh(mysh_t *data);
void error(char *str);

char **add_tab_line(char **tab, char *string);
void copy_of_env(mysh_t *data, char **env);
void initialise_value(mysh_t *data);
void sigint_handler(int signum);
int status_handler(int status);
int wait_command(mysh_t *data);
void free_utils(mysh_t *data);
int get_command(mysh_t *data);

char *get_path(char **env);
char *get_pwd(char **env, char *path);
int find_the_correct_path(mysh_t *data);
void concat(mysh_t *data, char *string);
void native_binary_process(mysh_t *data, int indic);
int execute_command(char **args, char **env, char *raw_cmd);

char *my_getenv(char **env, char *name);
int cmd_detector_main(mysh_t *data);
void already_exist(mysh_t *data);
void child_error(char *raw_cmd);
int my_unsetenv(mysh_t *data);
int my_exit(mysh_t *data);
int my_env(mysh_t *data);
int my_echo(mysh_t *data);
int my_previous_command(mysh_t *data);

int my_cd(mysh_t *data);
char *cd_wave(mysh_t *data, char *path);
char *choose_cd(mysh_t *data, char *path);
int free_new_path(mysh_t *data, char *path);

int my_history(mysh_t *data);
list_t *create_history(char *cmd_raw);
void push_history(list_t **head, char *cmd_raw_dup);
void display_history(mysh_t *mysh);
void free_history(list_t **head);

void format_string(mysh_t *data);
void verif_string(mysh_t *data);
int verif_setenv(mysh_t *data);
int find_equal(mysh_t *data);
int my_setenv(mysh_t *data);
int my_isupper(int c);

void pipes(mysh_t *data, complex_t *info, int i);
void wait_child(int cmd_piped, pid_t *child_pid, mysh_t *data);
void destroy_pipes(int cmd_piped, int **pipes);
void free_pipes(int cmd_piped, int **pipes);
int create_pipes(int cmd_piped, int **pipes);
void destroy_pipes(int cmd_piped, int **pipes);
void redirection_std(int cmd_piped, int **pipes, int i);
void close_read_and_write(int cmd_piped, int **pipes, int i);
int **create_pipes_array(int cmd_piped);
char ***allocate_commands(int cmd_piped, char **cmd, int d);
void close_pipes(int cmd_piped, int **pipes, int i);
int nbr_piped(char **cmd, int i, complex_t *info);
void redirect_pipes(complex_t *info);
char *find_file(mysh_t *data, int i);
void error_with_cmd(int recup, char **raw_cmd, int i);
char **get_raw_cmd(int cmd_piped, char ***cmd);
int verif_pipe(char **cmd, int index, mysh_t *data);

void complex_main(mysh_t *data);
void set_data(complex_t *info);
void complex_execution(mysh_t *data, complex_t *info, int i);
int simple_execution(mysh_t *data, complex_t *info, char *raw_cmd);
void complex_path(char **tab, char *path, char *pwd);
void free_cmd(char ***cmd, int cmd_piped);
bool redirect_output_save(mysh_t *data, complex_t *info, int i);
void double_in(mysh_t *data, complex_t *info, int *i);
int double_in_execution(mysh_t *data, char *raw_cmd, char **input, int i);

void copying(mysh_t *data, char *line);
bool its_complex(char *line);
void classic_execution(mysh_t *data);
char *format_path(char *path);
void child_error(char *raw_cmd);
void execute_handler(mysh_t *data, char *raw_cmd);
void set_info(mysh_t *data);
void save_or_clear(mysh_t *data, complex_t *info, int i);
int pipe_detect(mysh_t *data, complex_t *info, int i);
void semicolon_execute(mysh_t *data, complex_t *info, int i);
void and_execute(mysh_t *data, complex_t *info, int i);
void double_pipe_execute(mysh_t *data, complex_t *info, int i);
int redirect_detect(mysh_t *data, complex_t *info, int *i);
void unix_setenv(char *variable_name, char *content, mysh_t *data);
void precmd(mysh_t *data);
void special_variables_set(mysh_t *data);
void recopy_env(int size, char **temp, mysh_t *data);
void term_type(mysh_t *data);

int check_events(char **line, char ch, int *idx, size_t *len);
int end_command(mysh_t *data, char *line, size_t len);
void set_path(char ***cmd, mysh_t *data);

#endif /* MY_SH_ */
