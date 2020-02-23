void drawLine_helper(coords *data, void *mlx_ptr, void *win_ptr, coords *num)
{
    int error;
    int error2;

    error = num->x1 - num->y1;
    mlx_pixel_put(mlx_ptr, win_ptr, data->x2, data->y2, 0xffffff);
    while (data->x1 != data->x2 || data->y1 != data->y2)
    {
        mlx_pixel_put(mlx_ptr, win_ptr, data->x1, data->y1, 0xffffff);
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

void drawLine(coords *data, void *mlx_ptr, void *win_ptr)
{
    coords *st_cont;
    int deltaX;
    int deltaY;
    int signX;
    int signY;

    st_cont = malloc(sizeof(coords));
    st_cont->x1 = abs(data->x2 - data->x1);     //dx
    st_cont->y1 = abs(data->y2 - data->y1);     //dy
    st_cont->x2 = data->x1 < data->x2 ? 1 : -1; //sx
    st_cont->y2 = data->y1 < data->y2 ? 1 : -1;
    drawLine_helper(data, mlx_ptr, win_ptr, st_cont);
    free(st_cont);
}