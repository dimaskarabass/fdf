#ifndef FDF_H
# define FDF_H

typedef struct p_list
{
	int     **init_arr;
	int     len;
	int     height;
}               returned;

typedef struct  g_list
{
	void    *win_id;
	void    *conn_id;
	double  **coef_arr;
	returned    *issues;
}               b_list;

typedef struct  f_list
{
	int         x1;
	int         y1;
	int         x2;
	int         y2;
}               coords;

#include <unistd.h>
#include "get_next_line.c"
#include <fcntl.h>
#include <math.h>
#include "libft/ft_strchr.c"
#include "libft/ft_strdel.c"
#include "libft/ft_strdup.c"
#include "libft/ft_strjoin.c"
#include "libft/ft_strsub.c"
#include "libft/ft_strlen.c"
#include "libft/ft_strcpy.c"
#include "libft/ft_putstr.c"
#include "libft/ft_putchar.c"

#define WHIDTH  1000
#define HIDHT   1000
#define INIT_A  0
#define INIT_B  0

#endif