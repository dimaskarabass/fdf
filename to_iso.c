#include  "fdf.h"

double		**mlpl_mtrx2(double m1[3][3], double m2[3][3])
{
	double 	**res;
	int 	i;
	int 	j;

	i = 0;
	j = 0;
	res = malloc(sizeof(double *) * 3);
	while (i < 3)
	{
		res[i] = malloc(sizeof(double) * 3);
		while (j < 3)
		{
			res[i][j] = m1[i][0] * m2[0][j] + m1[i][1] * m2[1][j] + m1[i][2] * m2[2][j];
			j++;
		}
		j = 0;
		i++;
	}
	return (res);
}

double		**mlpl_mtrx(double **m1, double m2[3][3])
{
	double 	**res;
	int 	i;
	int 	j;

	i = 0;
	j = 0;
	res = malloc(sizeof(double *) * 3);
	while (i < 3)
	{
		res[i] = malloc(sizeof(double) * 3);
		while (j < 3)
		{
			res[i][j] = m1[i][0] * m2[0][j] + m1[i][1] * m2[1][j] + m1[i][2] * m2[2][j];
			j++;
		}
		j = 0;
		i++;
	}
	return (res);
}

int			*mltpl_mtrx4(double **matrix, int *p, int z, int c)
{
	int 	*res;
	int 	i;
	int 	j;

	i = 0;
	j = 0;
	res = malloc(sizeof(int) * 3);
	while (i < 3)
	{
		res[i] = matrix[i][0] * p[0] * c + matrix[i][1] * p[1]  * c + matrix[i][2] * z * c;
		i++;
	}
	return res;
}

int arr_max(returned cont)
{
	int max;
	int i;
	int j;

	i = 0;
	j = 0;
	max = cont.init_arr[0][0];
	while (i < cont.height)
	{
		while (j < cont.len)
		{
			if (cont.init_arr[i][j] > max)
				max = cont.init_arr[i][j];
			j++;
		}
		j = 0;
		i++;
	}
	return (max);
}

int arr_min(returned cont)
{
	int min;
	int i;
	int j;

	i = 0;
	j = 0;
	min = cont.init_arr[0][0];
	while (i < cont.height)
	{
		while (j < cont.len)
		{
			if (cont.init_arr[i][j] < min)
				min = cont.init_arr[i][j];
			j++;
		}
		j = 0;
		i++;
	}
	return (min);
}
