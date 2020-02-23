.PHONY: all clean fclean re
NAME = fdf
SRCS =	alg.c \
	reader.c \
	to_iso.c \
	get_next_line.c \
	main.c \
	rot.c
OBJS = $(SRCS:.c=.o)
HEADER_DIR = src/
CC = gcc
FLAGS = -Wall -Wextra -Werror
EXTRA_FLAGS = -L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit libft/libft.a
HEADER = mlx.h
all: $(NAME)
$(NAME):
	$(CC) $(SRCS) $(EXTRA_FLAGS)
clean:
	/bin/rm -f src/*.o
	/bin/rm -f src/*.gch
fclean: clean
	/bin/rm -f $(NAME)
re: fclean all
