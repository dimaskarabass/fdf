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

int			*mltpl_mtrx4(double **matrix, int x, int y, int z)
{
	int 	*res;
	int 	i;
	int 	j;

	i = 0;
	j = 0;
	res = malloc(sizeof(int) * 3);
	while (i < 3)
	{
		res[i] = matrix[i][0] * x * COEF + matrix[i][1] * y  * COEF + matrix[i][2] * z * COEF;
		i++;
	}
	return res;
}

void		to_iso_len(b_list *cont, double **m1)
{
	int i;
	int j;
	int *p1;
	int *p2;

	i = 0;
	j = 0;
	while (j < cont->issues->len)
	{
		while (i < cont->issues->height - 1)
		{
			p1 = mltpl_mtrx4(m1, i, j, cont->issues->init_arr[i][j]);
			i++;

			p2 = mltpl_mtrx4(m1, i, j, cont->issues->init_arr[i][j]);
			drawLine(WHIDTH/2 + p1[0], HIDHT/3 + p1[1], WHIDTH/2 + p2[0], HIDHT/3 + p2[1], cont->conn_id, cont->win_id);
		}
		i = 0;
		j++;
	}
}

void		to_iso_height(b_list *cont, double **m1)
{
	int i;
	int j;
	int *p1;
	int *p2;

	i = 0;
	j = 0;
	while (i < cont->issues->height)
	{
		while (j < cont->issues->len - 1)
		{
			p1 = mltpl_mtrx4(m1, i, j, cont->issues->init_arr[i][j]);
			j++;

			p2 = mltpl_mtrx4(m1, i, j, cont->issues->init_arr[i][j]);
			drawLine(WHIDTH/2 + p1[0], HIDHT/3 + p1[1], WHIDTH/2 + p2[0], HIDHT/3 + p2[1], cont->conn_id, cont->win_id);
		}
		j = 0;
		i++;
	}
}

void		to_iso(b_list *cont, double **m1)
{
	to_iso_len(cont, m1);
	to_iso_height(cont, m1);
}