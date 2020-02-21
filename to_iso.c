#include  "../../Documents/fdf/fdf.h"

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

int			*mltpl_mtrx4(double **matrix, int x, int y, int z, int c)
{
	int 	*res;
	int 	i;
	int 	j;

	i = 0;
	j = 0;
	res = malloc(sizeof(int) * 3);
	while (i < 3)
	{
		res[i] = matrix[i][0] * x * c + matrix[i][1] * y  * c + matrix[i][2] * z * c;
		i++;
	}
	return res;
}


void		to_iso_len(b_list *cont, double **m1, int c)
{
	int i;
	int j;
	int *p1;
	int *p2;
	coords *saver;

	i = 0;
	j = 0;
	saver = (coords *)malloc(sizeof(coords));
	while (j < cont->issues->len)
	{
		while (i < cont->issues->height - 1)
		{
			p1 = mltpl_mtrx4(m1, i, j, cont->issues->init_arr[i][j], c);
			saver->x1 = WHIDTH/2 + p1[0];
			saver->y1 = HIDHT/2 + p1[1];
			i++;
			p2 = mltpl_mtrx4(m1, i, j, cont->issues->init_arr[i][j], c);
			saver->x2 = WHIDTH/2 + p2[0];
			saver->y2 = HIDHT/2 + p2[1];
			drawLine(saver, cont->conn_id, cont->win_id);
		}
		i = 0;
		j++;
	}
}

void		to_iso_height(b_list *cont, double **m1, int c)
{
	int i;
	int j;
	int *p1;
	int *p2;
	coords *saver;

	i = 0;
	j = 0;
	saver = (coords *)malloc(sizeof(coords));
	while (i < cont->issues->height)
	{
		while (j < cont->issues->len - 1)
		{
			p1 = mltpl_mtrx4(m1, i, j, cont->issues->init_arr[i][j], c);
			saver->x1 = WHIDTH/2 + p1[0];
			saver->y1 = HIDHT/2 + p1[1];
			j++;
			p2 = mltpl_mtrx4(m1, i, j, cont->issues->init_arr[i][j], c);
			saver->x2 = WHIDTH/2 + p2[0];
			saver->y2 = HIDHT/2 + p2[1];
			drawLine(saver, cont->conn_id, cont->win_id);
		}
		j = 0;
		i++;
	}
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

void		to_iso(b_list *cont, double **m1)
{
	int max_z;
	int min_z;
	int c;

	max_z = arr_max(*(cont->issues));
	min_z = arr_min(*(cont->issues));
	c = sqrt(cont->issues->len * cont->issues->len + cont->issues->height * cont->issues->height);
	if (fabs((double)max_z) + fabs((double)min_z) > c)
		c = fabs((double)max_z) + fabs((double)min_z) / 2;
	c = HIDHT / (2 * c);
	to_iso_len(cont, m1, c);
	to_iso_height(cont, m1, c);
}