NAME= pipex

SRC = main.c split.c ft_strjoin.c pipex_utils.c pipex.c

CC      = gcc
FLAGS	= -Werror -Wextra -Werror -g -I.

ifeq (${DEBUG}, 1)
	FLAGS	+= -g
endif

OBJ = $(SRC:.c=.o)


${NAME}: ${OBJ} ${MLX}
	$(CC) $(OBJ) $(LIB) -o $@

target/ruleName: dep0 dep1 dep2 ... depN
	instruct 0
	instruct 1
	...
	$< la premiere dep
	$@ la target
	$^ 



%.o: %.c
	${CC} ${FLAGS} -c $< -o $@

all: $(NAME)


clean:
	${RM} ${OBJ}

fclean: clean
	${RM} ${NAME}
	

re: fclean all

.PHONY : all clean fclean re 