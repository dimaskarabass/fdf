#include "fdf.h"

int			closer(void *param)
{
	(void)param;
	exit(0);
}

void		helper(void *param, double m[3][3])
{
	((b_list *)param)->coef_arr = mlpl_mtrx(((b_list *)param)->coef_arr, m);
	mlx_clear_window(((b_list *)param)->conn_id, ((b_list *)param)->win_id);
	to_iso((b_list *)param, ((b_list *)param)->coef_arr);
}

void		rot_x(void *param)
{
	double m1[3][3];

	m1[0][0] = 1;
	m1[0][1] = 0;
	m1[0][2] = 0;
	m1[1][0] = 0;
	m1[1][1] = cos(0.1);
	m1[1][2] = -sin(0.1);
	m1[2][0] = 0;
	m1[2][1] = sin(0.1);
	m1[2][2] = cos(0.1);
	helper(param, m1);
}

void		rot_y(void *param)
{
	double m2[3][3];

	m2[0][0] = cos(0.1);
	m2[0][1] = 0;
	m2[0][2] = -sin(0.1);
	m2[1][0] = 0;
	m2[1][1] = 1;
	m2[1][2] = 0;
	m2[2][0] = sin(0.1);
	m2[2][1] = 0;
	m2[2][2] = cos(0.1);
	helper(param, m2);
}

void		rot_z(void *param)
{
	double m3[3][3];

	m3[0][0] = cos(0.1);
	m3[0][1] = -sin(0.1);
	m3[0][2] = 0;
	m3[1][0] = sin(0.1);
	m3[1][1] = cos(0.1);
	m3[1][2] = 0;
	m3[2][0] = 0;
	m3[2][1] = 0;
	m3[2][2] = 1;
	helper(param, m3);
}
