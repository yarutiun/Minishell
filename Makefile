NAME = minishell
LIB_F = libft
LIB = libft.a
SRC = src
OBJ = obj
INC = inc
CFLAGS = -g -I$(INC) -Wall -Wextra -Werror
RM = rm -rf
CC = gcc
SRCS =	src/main.c\
		src/pwd.c\
		src/envp.c\
		src/lexer/lexer.c\
		src/lexer/lists.c\
		src/lexer/utils.c\
		src/parser/parser.c\
		src/parser/pipex.c\
		# src/error_handler.c\ //later

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIB_F)/$(LIB)
	@$(CC) $(CFLAGS) $(OBJS) $(LIB_F)/$(LIB) -o $(NAME) -lreadline

$(LIB_F)/$(LIB):
	@make -C $(LIB_F)
	@echo "libft is done!"

clean:
	@$(RM) $(OBJS)
	rm -rf obj 
	@echo "successfuly cleaned"

fclean: clean
	@$(RM) $(NAME)
	@make fclean -C $(LIB_F)
	@echo "executable removed successfuly"

leaks:
	make
	leaks --atExit -- ./minishell

re: fclean all