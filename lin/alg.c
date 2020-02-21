#include "fdf.h"

void drawLine(returned *data, void *mlx_ptr, void *win_ptr)
{
	int deltaX;
	int deltaY;
	int signX;
	int error;
	int signY;

	deltaX = abs(data -> x2 - data -> x1);
	deltaY = abs(data -> y2 - data -> y1);
	signX = data -> x1 < data -> x2 ? 1 : -1;
	signY = data -> y1 < data ->y2 ? 1 : -1;
	error = deltaX - deltaY;

	mlx_pixel_put(mlx_ptr, win_ptr, data -> x2, data -> y2, 150);
	while(data -> x1 != data -> x2 || data -> y1 != data -> y2)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, data -> x1, data -> y1, 150);
		const int error2 = error * 2;
		if (error2 > -deltaY)
		{
			error -= deltaY;
			data -> x1 += signX;
		}
		if (error2 < deltaX)
		{
			error += deltaX;
			data -> y1 += signY;
		}
	}
}