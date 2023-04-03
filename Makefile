NAME = minishell
LIB_F = libft
LIB = libft.a
SRC = src
OBJ = obj
INC = inc
CFLAGS = -Wall -Wextra -Werror -g -I $(INC)
DEBUG_SEG_FAULTS = -fsanitize=address #for segfault checking
RM = rm -rf
CC = gcc
SRCS = src/main.c src/utils.c src/lexer.c src/expander.c src/find_env.c src/env.c src/pwd.c src/redirection.c src/executor.c \
		src/cd.c src/export.c src/exit.c src/echo.c src/unset.c src/free.c src/error.c \
		src/signals.c src/handle.c src/executor2.c src/expander2.c src/redirection2.c src/lexer2.c src/export2.c \
		src/utils2.c src/lexer3.c src/redirection3.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIB_F)/$(LIB)
	@$(CC) $(CFLAGS) $(DEBUG_SEG_FAULTS) $(OBJS) $(LIB_F)/$(LIB) -o $(NAME)  -lreadline

$(LIB_F)/$(LIB):
	@make -C $(LIB_F)
	@echo "libft is done!"

clean:
	@$(RM) $(OBJS)
	@rm -rf obj
	@echo "successfuly cleaned"

fclean: clean
	@$(RM) $(NAME)
	@make fclean -C $(LIB_F)
	@echo "executable removed successfuly"

re: fclean all
