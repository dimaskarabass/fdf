.PHONY: all clean fclean re
NAME = fdf
SRCS =	alg.c \
	reader.c \
	to_iso.c \
	get_next_line.c \
	main.c \
	iso.c \
	rot.c
OBJS = $(SRCS:.c=.o)
HEADER_DIR = src/
CC = gcc
FLAGS = -Wall -Wextra -Werror
EXTRA_FLAGS = -L/usr/X11/lib -lmlx -lXext -lX11 -lpthread -lm libft/libft.a
HEADER = mlx.h
all: $(NAME)
$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $@  $(EXTRA_FLAGS)
clean:
	/bin/rm -f src/*.o
	/bin/rm -f src/*.gch
	rm -f *.o
fclean: clean
	/bin/rm -f $(NAME)
re: fclean all
