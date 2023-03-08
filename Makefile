
	### COMPILATION ###

CC			= gcc -g3 -fsanitize=address
FLAGS		= -Wall -Werror -Wextra

	### EXECUTABLE ###

NAME		= minishell

	### PATH ###

SRCS_PATH	= srcs
OBJS_PATH	= objs
INCS_PATH	= -Iincl

	### SOURCE FILE ###

SOURCES		= main.c

	# ENVIRONMENT

ENV_FILES	= ft_initenv.c\
			  ft_get_path.c\
			  ft_setenv.c\
			  ft_getenv.c\
			  ft_unsetenv.c

	# EXIT

EXIT_FILES	= ft_exit.c\
			  ft_free_allocation.c

	# INIT_DATA

INIT_FILES	= ft_init_minishell.c\
			  ft_init_cmd.c

	# PARSING

PARS_FILES	= ft_getword.c\
			  ft_lenword.c\
			  ft_parse_token.c\
			  ft_parse_varenv.c\
			  ft_parsing.c\
			  ft_redirection.c\
			  ft_token_type.c\
			  ft_tokenizing_prompt.c

	# SIGNALS

SIGN_FILES	= ft_init_signals.c\
			  ft_handle_signals.c

	# SIGNALS

EXEC_FILES	= ft_execute.c

	# BUILTINS
BUILT_FILES	= ft_cd.c\
			  ft_env.c\
			  ft_pwd.c

	# UTILS

UTILS_FILES	= ft_memory_allocation.c\
			  ft_split.c\
			  ft_utils_list.c\
			  utils.c

VENV_FILES	= ft_parse_varenv.c\

	# ALL FILES

FILES		= $(SOURCES)\
			  $(ENV_FILES)\
			  $(EXIT_FILES)\
			  $(INIT_FILES)\
			  $(UTILS_FILES)\
			  $(PARS_FILES)\
			  $(SIGN_FILES)\
			  $(EXEC_FILES)\
			  $(BUILT_FILES)\
			  $(VENV_FILES)

	### OBJECTS ###

ENV_FILES	:= $(addprefix environment/, $(ENV_FILES))
EXIT_FILES	:= $(addprefix exit/, $(EXIT_FILES))
INIT_FILES	:= $(addprefix init_minishell/, $(INIT_FILES))
PARS_FILES	:= $(addprefix parsing/, $(PARS_FILES))
UTILS_FILES	:= $(addprefix utils/, $(UTILS_FILES))
SIGN_FILES	:= $(addprefix signals/, $(SIGN_FILES))
EXEC_FILES	:= $(addprefix execute/, $(EXEC_FILES))
BUILT_FILES	:= $(addprefix builtins/, $(BUILT_FILES))
VENV_FILES	:= $(addprefix variable_env/, $(VENV_FILES))

SRCS		= $(addprefix $(SRCS_PATH)/, $(FILES))
OBJS		= $(addprefix $(OBJS_PATH)/, $(FILES:.c=.o))

	### LIBS ###

LIBS		= -lreadline

	### COLORS ###

RED			= \033[1;31m
GREEN		= \033[1;32m
YELLOW		= \033[1;33m
BLUE		= \033[1;34m
VIOLET		= \033[1;35m
CYAN		= \033[1;36m
NOC			= \033[0m
WHITE		= \033[1;37m

	### READLINE PATH ###

ifdef READLINE
	LIBS_PATH	+= -L$(READLINE)/lib
	INCS_PATH	+= -I$(READLINE)/include
endif

	### RULES ###

all:		tmp $(NAME)

$(NAME):	$(OBJS)
			@echo "$(BLUE)##### Compiling Project #####$(WHITE)"
			$(CC) $(FLAGS) $(LIBS_PATH) $(LIBS) -o $@ $^
			@echo "$(GREEN)##### Project Compilated #####$(WHITE)"

tmp:
			@echo "$(CYAN)##### Compiling SRCS in OBJS #####$(WHITE)"
			@mkdir -p objs

$(OBJS_PATH)/%.o:	$(SRCS_PATH)/%.c
					@mkdir -p $(@D)
					$(CC) $(FLAGS) $(INCS_PATH) -c $< -o $@

clean:
			@echo "$(VIOLET)##### Supressing FILES #####$(YELLOW)"
			rm -rf $(OBJS_PATH)

fclean:		clean
			@echo "$(VIOLET)##### Supressing EXEC and LIBS #####$(YELLOW)"
			rm -rf $(NAME)

re:			fclean all

.PHONY:		clean, fclean, re, tmp, all, minishell
