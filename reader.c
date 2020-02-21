#include <fcntl.h>


void freesher(double **arr)
{
	int i;

	i = 0;
	while(i < 3)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

int find_size(char *file)
{
	int fd;
	int len;
	char *line;

	len = 0;
	fd = open(file, O_RDONLY);
	while (get_next_line(fd, &line))
		len++;
	close(fd);
	return (len);
}

void prnt_rr(double **arr, int i, int j)
{
	int p;
	int f;

	p = 0;
	f = 0;
	while (p < i)
	{
		while (f < j)
		{
			printf("%f\t", arr[p][f]);
			f++;
		}
		f = 0;
		printf("\n");
		p++;
	}
}

returned *helper_for_read(int fd, int height, int len, returned *lol)
{
	int    **init_arr;
	char    **arr;
	char    *line;
	int     i;
	int     j;

	j = 0;
	i = 0;
	init_arr = malloc(sizeof(int *) * (height));
	while(get_next_line(fd, &line))
	{
		j = 0;
		arr = ft_strsplit(line, ' ');
		while (arr[len])
			len++;
		init_arr[i] = malloc(sizeof(int) * (len));
		while(j < len)
		{
			init_arr[i][j] = ft_atoi(arr[j]);
			j++;
		}
		i++;
	}
	lol->init_arr = init_arr;
	lol->height = height;
	lol->len = len;
	return(lol);
}

returned *reader(char *file)
{
	int fd;
	char **arr;
	int len;
	int height;
	returned    *lol;

	len = 0;
	height = find_size(file);
	fd = open(file, O_RDONLY);
	lol = malloc(sizeof(returned));
	return (helper_for_read(fd, height, len, lol));
}