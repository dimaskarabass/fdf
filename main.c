#include "fdf.h"

int		deal_key(int key, void *param)
{
	if (key == 0)
		rot_x(param);
	if (key == 1)
		rot_y(param);
	if (key == 2)
		rot_z(param);
	if (key == 53)
		closer((void *)param);
	return (0);
}

void	dfreesher(double **issues)
{
	int i;

	i = 0;
	while (i < 3)
	{
		free(issues[i]);
		i++;
	}
	free(issues);
}

double	**init_arr(void *everything)
{
    double **coef_arr;
    double **coef_arr2;
	double m1[3][3];
	double m2[3][3];
	double m3[3][3];
	
	m1[0][0] = 1;
	m1[0][1] = 0;
	m1[0][2] = 0;
	m1[1][0] = 0;
	m1[1][1] = cos(INIT_A2);
	m1[1][2] = sin(INIT_A2);
	m1[2][0] = 0;
	m1[2][1] = -sin(INIT_A2);
	m1[2][2] = cos(INIT_A2);

	m2[0][0] = cos(INIT_Z2);
	m2[0][1] = 0;
	m2[0][2] = -sin(INIT_Z2);
	m2[1][0] = 0;
	m2[1][1] = 1;
	m2[1][2] = 0;
	m2[2][0] = sin(INIT_Z2);
	m2[2][1] = 0;
	m2[2][2] = cos(INIT_Z2);

	m3[0][0] = cos(INIT_B2);
	m3[0][1] = -sin(INIT_B2);
	m3[0][2] = 0;
	m3[1][0] = sin(INIT_B2);
	m3[1][1] = cos(INIT_B2);
	m3[1][2] = 0;
	m3[2][0] = 0;
	m3[2][1] = 0;
	m3[2][2] = 1;
	
	coef_arr = mlpl_mtrx2(m1, m3);
	coef_arr2 = mlpl_mtrx(coef_arr, m2);
	to_iso((b_list *)everything, coef_arr2);
	dfreesher(coef_arr);
	return (coef_arr2);
}

void		ifreesher(returned *issues)
{
	int	i;

	i = 0;
	while (i < issues->height)
	{
		free(issues->init_arr[i]);
		i++;
	}
	free(issues->init_arr);
	free(issues);
}

void		idfreesher(b_list *issues)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		free(issues->coef_arr);
		i++;
	}
	free(issues->coef_arr);
	free(issues);
}

int	main(int argc, char **argv)
{
	void		*win_id;
	void		*conn_id;
	b_list		*wraper;
	int			**arr;
	returned	*test;

	if (argc != 2)
	{
		ft_putstr("Usage : ./fdf <filename> [ case_size z_size ]\n");
		return (0);
	}
	wraper = malloc(sizeof(b_list));
	test = reader(argv[1]);
	wraper->issues = *test;
	free(test);
	conn_id = mlx_init();
	win_id = mlx_new_window(conn_id, WHIDTH, HIDHT, "FDF");
	wraper->win_id = win_id;
	wraper->conn_id = conn_id;
	wraper->coef_arr = init_arr((void *)wraper);
	mlx_hook(win_id, 2, 0, deal_key, (void *)wraper);
	mlx_loop(conn_id);
	return (0);
}
