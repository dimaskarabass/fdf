#ifndef FDF_H
# define FDF_H

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

#define WHIDTH  1500
#define HIDHT   1000
#define COEF    20
#define INIT_A  0
#define INIT_B  0

typedef struct p_list
{
	int     **init_arr;
	int     len;
	int     height;
}               returned;

typedef struct	g_list
{
	void    *win_id;
	void    *conn_id;
	double  **coef_arr;
	returned    *issues;
}               b_list;

typedef struct g_coor
{
	int		x1;
	int 	x2;
	int		y1;
	int 	y2;
}				b_coor;

#endif