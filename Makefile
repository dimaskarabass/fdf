.PHONY: all clean fclean re
NAME = fdf
SRCS = main.c
OBJS = $(SRCS:.c=.o)
HEADER_DIR = src/
CC = gcc
FLAGS = -Wall -Wextra -Werror
EXTRA_FLAGS = -L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit
HEADER = mlx.h
all: $(NAME)
$(NAME):
	$(CC) $(SRCS) $(EXTRA_FLAGS)
#%.o:%.c ${HEADER}
#	gcc $(FLAGS) -I $(HEADER_DIR) -c $< -o $@
clean:
	/bin/rm -f src/*.o
	/bin/rm -f src/*.gch
fclean: clean
	/bin/rm -f $(NAME)
re: fclean all