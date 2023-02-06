NAME = minishell
LIB_F = libft
LIB = libft.a
SRC = src
OBJ = obj
INC = inc
CFLAGS = -Wall -Wextra -Werror -g -I$(INC)
RM = rm -rf
CC = gcc
SRCS =	src/main.c\
		src/utils.c\
		src/lexer.c\
		src/init_enviroment.c\
		src/error_handler\

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
