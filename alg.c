void drawLine(int x1, int y1, int x2, int y2, void *mlx_ptr, void *win_ptr)
{
	const int deltaX = abs(x2 - x1);
	const int deltaY = abs(y2 - y1);
	const int signX = x1 < x2 ? 1 : -1;
	const int signY = y1 < y2 ? 1 : -1;

	int error = deltaX - deltaY;

	mlx_pixel_put(mlx_ptr, win_ptr, x2, y2, 150);
//	setPixel(x2, y2);
	while(x1 != x2 || y1 != y2)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, x1, y1, 150);
		const int error2 = error * 2;
		//
		if(error2 > -deltaY)
		{
			error -= deltaY;
			x1 += signX;
		}
		if(error2 < deltaX)
		{
			error += deltaX;
			y1 += signY;
		}
	}
}