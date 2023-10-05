##
## EPITECH PROJECT, 2022
## makefile
## File description:
## makefile
##

CC = gcc

SOURCE =	src/

EXECUTE	=	src/execute_cmd/complex_execution/

PERSONNAL_CMD = src/personnal_cmd/

SPECIAL_VARIABLES =	src/special_variable/

SRC =	$(SOURCE)main.c	\
		$(SOURCE)find_path/concat.c	\
		$(SOURCE)find_path/get_path.c	\
		$(SOURCE)utils/get_pwd.c	\
		$(SOURCE)execute_cmd/execute_command.c	\
		$(SOURCE)execute_cmd/status_handler.c	\
		$(SOURCE)execute_cmd/classic_execution.c	\
		$(SOURCE)execute_cmd/child_error.c	\
		$(SOURCE)utils/copy_of_env.c	\
		$(SOURCE)utils/error.c	\
		$(SOURCE)utils/initialise_value.c	\
		$(SOURCE)utils/add_tab_line.c	\
		$(SOURCE)utils/copying.c	\
		$(SOURCE)utils/my_tabdup.c	\
		$(SOURCE)find_path/find_the_correct_path.c	\
		$(SOURCE)find_path/format_path.c	\
		$(SOURCE)termios/stdin_events.c	\
		$(SOURCE)termios/end_command.c	\
		$(SPECIAL_VARIABLES)special_variable_set.c	\
		$(SPECIAL_VARIABLES)unix_setenv.c	\
		$(SPECIAL_VARIABLES)term_type.c	\
		$(SPECIAL_VARIABLES)precmd.c	\
		$(PERSONNAL_CMD)unsetenv/my_unsetenv.c	\
		$(PERSONNAL_CMD)exit/my_exit.c	\
		$(PERSONNAL_CMD)print_env/my_env.c	\
		$(PERSONNAL_CMD)getenv/my_getenv.c	\
		$(PERSONNAL_CMD)cd/my_cd.c	\
		$(PERSONNAL_CMD)cd/choose_cd.c	\
		$(PERSONNAL_CMD)cd/free_new_path.c	\
		$(PERSONNAL_CMD)setenv/my_setenv.c	\
		$(PERSONNAL_CMD)setenv/verif_setenv.c	\
		$(PERSONNAL_CMD)setenv/my_isupper.c	\
		$(PERSONNAL_CMD)setenv/already_exist.c	\
		$(PERSONNAL_CMD)cmd_detector_main.c	\
		$(PERSONNAL_CMD)pipes/pipes.c	\
		$(PERSONNAL_CMD)pipes/wait_and_errno.c	\
		$(PERSONNAL_CMD)pipes/destroy_pipes.c	\
		$(PERSONNAL_CMD)pipes/free_pipes.c	\
		$(PERSONNAL_CMD)pipes/create_pipes.c	\
		$(PERSONNAL_CMD)pipes/close_pipes.c	\
		$(PERSONNAL_CMD)pipes/redirection_std.c	\
		$(PERSONNAL_CMD)pipes/close_read_and_write.c	\
		$(PERSONNAL_CMD)pipes/create_pipes_array.c	\
		$(PERSONNAL_CMD)pipes/allocate_commands.c	\
		$(PERSONNAL_CMD)pipes/nbr_piped.c	\
		$(PERSONNAL_CMD)pipes/pipe_file.c	\
		$(PERSONNAL_CMD)pipes/free_array_of_array.c	\
		$(PERSONNAL_CMD)pipes/error_with_cmd.c	\
		$(PERSONNAL_CMD)pipes/get_raw_cmd.c	\
		$(PERSONNAL_CMD)pipes/verif_pipe.c	\
		$(PERSONNAL_CMD)pipes/set_path.c	\
		$(PERSONNAL_CMD)history/my_history.c \
		$(PERSONNAL_CMD)history/create_history.c	\
		$(PERSONNAL_CMD)history/free_history.c	\
		$(PERSONNAL_CMD)history/push_history.c	\
		$(PERSONNAL_CMD)history/display_history.c	\
		$(PERSONNAL_CMD)echo/echo.c		\
		$(EXECUTE)complex_main.c	\
		$(EXECUTE)set_data.c	\
		$(EXECUTE)set_info.c	\
		$(EXECUTE)execute_handler.c	\
		$(EXECUTE)simple_execution.c	\
		$(EXECUTE)complex_execution.c	\
		$(EXECUTE)complex_path.c	\
		$(EXECUTE)redirect_output_save.c	\
		$(EXECUTE)double_in.c	\
		$(EXECUTE)double_in_execution.c	\
		$(EXECUTE)save_or_clear.c	\
		$(EXECUTE)pipe_detect.c	\
		$(EXECUTE)semicolon_execute.c	\
		$(EXECUTE)and_execute.c	\
		$(EXECUTE)double_pipe_execute.c	\
		$(EXECUTE)redirect_detect.c	\
		$(SOURCE)utils/free_utils.c	\
		$(SOURCE)utils/signal_handler.c	\
		$(SOURCE)utils/get_command.c

OBJ	=	$(SRC:.c=.o)

NAME	=	shell

CPPFLAGS = -iquote./include/

CFLAGS	= -Wall -Wextra -Werror -lncurses

LDFLAGS = -L./lib/my

LDLIBS = -lmy

all:	$(NAME)

debug: CFLAGS += -g3

debug: clean $(NAME)

valgrind: debug
	valgrind ./$(NAME)

$(NAME):	$(OBJ)
	make -C lib/my/
	$(CC) -o $(NAME) $(SRC) $(CPPFLAGS) $(CFLAGS) $(LDFLAGS) $(LDLIBS)

clean :
	make -C lib/my/ clean
	rm -f $(OBJ)

fclean: clean
	make -C lib/my/ fclean
	rm -f $(NAME)

re:     fclean all

.PHONY: all clean fclean re debug
