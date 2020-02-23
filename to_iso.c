#include  "./fdf.h"

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

void        helper_to_iso_l(b_list *cont, double **m1, coords *saver, coords *saver2)
{
    int *p1;
    int *p2;

    p2 = malloc(sizeof(int) * 2);
    while (saver2->y1 < cont->issues->len)
    {
        while (saver2->x1 < cont->issues->height - 1)
        {
            p2[0] = saver2->x1;
            p2[1] = saver2->y1;
            p1 = mltpl_mtrx4(m1, p2, cont->issues->init_arr[saver2->x1][saver2->y1], saver2->x2);
            saver->x1 = WHIDTH/2 + p1[0];
            saver->y1 = HIDHT/2 + p1[1];
            free(p1);
            saver2->x1++;
            p2[0] = saver2->x1;
            p1 = mltpl_mtrx4(m1, p2, cont->issues->init_arr[saver2->x1][saver2->y1], saver2->x2);
            saver->x2 = WHIDTH/2 + p1[0];
            saver->y2 = HIDHT/2 + p1[1];
            free(p1);
            drawLine(saver, cont->conn_id, cont->win_id);
        }
        saver2->x1 = 0;
        saver2->y1++;
    }
}

void        helper_to_iso_h(b_list *cont, double **m1, coords *saver, coords *saver2)
{
    int *p1;
    int *p2;

    p2 = malloc(sizeof(int) * 2);
    while (saver2->x1 < cont->issues->height)
    {
        while (saver2->y1 < cont->issues->len - 1)
        {
            p2[0] = saver2->x1;
            p2[1] = saver2->y1;
            p1 = mltpl_mtrx4(m1, p2, cont->issues->init_arr[saver2->x1][saver2->y1], saver2->x2);
            saver->x1 = WHIDTH/2 + p1[0];
            saver->y1 = HIDHT/2 + p1[1];
            free(p1);
            saver2->y1++;
            p2[1] = saver2->y1;
            p1 = mltpl_mtrx4(m1, p2, cont->issues->init_arr[saver2->x1][saver2->y1], saver2->x2);
            saver->x2 = WHIDTH/2 + p1[0];
            saver->y2 = HIDHT/2 + p1[1];
            free(p1);
            drawLine(saver, cont->conn_id, cont->win_id);
        }
        saver2->y1 = 0;
        saver2->x1++;
    }
}

void		to_iso_len(b_list *cont, double **m1, int c)
{
    coords  *saver;
    coords  *saver2;

    saver2 = malloc(sizeof(coords));
    saver2->x1 = 0; //i
    saver2->y1 = 0; //j
    saver2->x2 = c;
    saver = (coords *)malloc(sizeof(coords));
    helper_to_iso_l(cont, m1, saver, saver2);
    free(saver);
    free(saver2);
}

void		to_iso_height(b_list *cont, double **m1, int c)
{
    coords *saver;
    coords  *saver2;

    saver2 = malloc(sizeof(coords));
    saver2->x1 = 0; //i
    saver2->y1 = 0; //j
    saver2->x2 = c;
    saver = (coords *)malloc(sizeof(coords));
    helper_to_iso_h(cont, m1, saver, saver2);
    free(saver);
    free(saver2);
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
		c = fabs((double)max_z) + fabs((double)min_z) / 3;
	c = HIDHT / (2 * c);
	to_iso_len(cont, m1, c);
	to_iso_height(cont, m1, c);
}