#ifndef FDF_H
# define FDF_H

#define WHIDTH  1000
#define HIDHT   1000
#define INIT_A  0
#define INIT_B  0

#include <stdio.h>
#include <fcntl.h>
#include <stdio.h>
#include <math.h>
#include <fcntl.h>
#include "libft/libft.h"
#include "get_next_line.h"
#include "mlx.h"

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

int		closer(void *param);
void 		helper(void *param, double m[3][3]);
void 		rot_x(void *param);
void 		rot_y(void *param);
void		rot_z(void *param);
int 		deal_key(int key, void *param);
double 		**init_arr(void *everything);
void 		ifreesher(returned *issues);
void 		idfreesher(b_list *issues);
double		**mlpl_mtrx(double **m1, double m2[3][3]);
double		**mlpl_mtrx2(double m1[3][3], double m2[3][3]);
int		*mltpl_mtrx4(double **matrix, int *p, int z, int c);
void 		helper_for_helper(int **init_arr, coords *cont);
void        	helper_to_iso_l(b_list *cont, double **m1, coords *saver, coords *saver2);
void        	helper_to_iso_h(b_list *cont, double **m1, coords *saver, coords *saver2);
void		to_iso_len(b_list *cont, double **m1, int c);
void		to_iso_height(b_list *cont, double **m1, int c);
int 		arr_max(returned cont);
int 		arr_min(returned cont);
void		to_iso(b_list *cont, double **m1);
void 		freesher(double **arr);
int 		find_size(char *file);
void 		prnt_rr(double **arr, int i, int j);
returned 	*helper_for_read(coords *cont, returned *lol, int **init_arr);
returned 	*reader(char *file);
void		drawLine(coords *data, void *mlx_ptr, void *win_ptr);
void		drawLine_helper(coords *data, void *mlx_ptr, void *win_ptr, coords *num);

#endif
