#include "fdf.h"
#include "mlx.h"

void	drawline_helper(coords *data, void *mlx_ptr, void *win_ptr, coords *num)
{
	int error;
	int error2;

	error = num->x1 - num->y1;
	mlx_pixel_put(mlx_ptr, win_ptr, data->x2, data->y2, 0x00FF00);
	while (data->x1 != data->x2 || data->y1 != data->y2)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, data->x1, data->y1, 0x00FF00);
		error2 = error * 2;
		if (error2 > -num->y1)
		{
			error -= num->y1;
			data->x1 += num->x2;
		}
		if (error2 < num->x1)
		{
			error += num->x1;
			data->y1 += num->y2;
		}
	}
}

void	drawline(coords *data, void *mlx_ptr, void *win_ptr)
{
	coords *st_cont;

	st_cont = malloc(sizeof(coords));
	st_cont->x1 = abs(data->x2 - data->x1);
	st_cont->y1 = abs(data->y2 - data->y1);
	st_cont->x2 = data->x1 < data->x2 ? 1 : -1;
	st_cont->y2 = data->y1 < data->y2 ? 1 : -1;
	drawline_helper(data, mlx_ptr, win_ptr, st_cont);
	free(st_cont);
}
