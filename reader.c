#include "fdf.h"

void		freesher(double **arr)
{
	int i;

	i = 0;
	while (i < 3)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

int			find_size(char *file)
{
	int		fd;
	int		height;
	char	*line;

	height = 0;
	fd = open(file, O_RDONLY);
	if (fd <= 0)
	{
		ft_putstr("No file ");
		ft_putstr(file);
		ft_putchar('\n');
		exit(0);
	}
	while (get_next_line(fd, &line))
	{
		height++;
	}
	free(line);
	close(fd);
	return (height);
}

void		helper_for_helper(int **init_arr, coords *cont)
{
	char		*line;
	char		**arr;
	int			j;

	while (get_next_line(cont->x1, &line))
	{
		j = 0;
		cont->y1 = 0;
		arr = ft_strsplit(line, ' ');
		while (arr[cont->y1])
			cont->y1++;
		if (cont->y1 != cont->y2)
		{
			ft_putstr("Found wrong line length. Exiting.\n");
			exit(0);
		}
		init_arr[cont->x2] = malloc(sizeof(int) * (cont->y1));
		while (j < cont->y1)
		{
			init_arr[cont->x2][j] = ft_atoi(arr[j]);
			j++;
		}
		cont->x2++;
		free(arr);
		free(line);
	}
}

returned	*helper_for_read(coords *cont, returned *lol, int **init_arr)
{
	char	**arr;
	char	*line;
	int		j;

	j = 0;
	get_next_line(cont->x1, &line);
	arr = ft_strsplit(line, ' ');
	while (arr[cont->y2])
		cont->y2++;
	init_arr[cont->x2] = malloc(sizeof(int) * (cont->y2));
	while (j < cont->y2)
	{
		init_arr[cont->x2][j] = ft_atoi(arr[j]);
		j++;
	}
	cont->x2++;
	helper_for_helper(init_arr, cont);
	lol->init_arr = init_arr;
	lol->len = cont->y1;
	free(arr);
	free(line);
	return (lol);
}

returned	*reader(char *file)
{
	coords			*cont;
	returned		*lol;
	int				**init_arr;

	cont = malloc(sizeof(coords));
	cont->y1 = 0;
	cont->x2 = 0;
	cont->x1 = open(file, O_RDONLY);
	cont->y2 = 0;
	lol = malloc(sizeof(returned));
	lol->height = find_size(file);
	init_arr = malloc(sizeof(int *) * (lol->height));
	return (helper_for_read(cont, lol, init_arr));
}
