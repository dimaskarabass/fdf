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
#define COS30   0.154
#define COS60   -0.952
#define SIN30   -0.988
#define SIN60   -0.304
#define COEF    20
#define INIT_A  0
#define INIT_B  0

#endif