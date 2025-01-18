#include "so_long.h"

char	*read_file(char	*path)
{
	char	*line;
	char	*ret;
	int		fd;
	int		i;

	fd = open(path, O_RDONLY);
	ret = ft_calloc(1, sizeof(char));
	while (1)
	{
		i = -1;
		line = get_next_line(fd);
		if (!line)
			break ;
		endln_control(line[0]);
		ret = ft_strjoin_free(ret, line);
		free(line);
	}
	close(fd);
	return (ret);
}

t_map	*read_map(char *path)
{
	t_map	*ret;
	char	*map;
	int		i;

	i = 0;
	ret = ft_calloc(1, sizeof(t_map));
	map = read_file(path);
	ret->inside = ft_split(map, '\n');
	ret->tmp_map = ft_split(map, '\n');
	ret->height = 0;
	while (ret->inside[ret->height])
		ret->height++;
	ret->width = ft_strlen(ret->inside[0]);
	free(map);
	return (ret);
}

void	put_img(char c, t_wndw *wndw, int x, int y)
{
	mlx_put_image_to_window(wndw->mlx, wndw->wndw, wndw->place, x, y);
	if (c == '1')
		mlx_put_image_to_window(wndw->mlx, wndw->wndw, wndw->wall, x, y);
	if (c == 'C')
		mlx_put_image_to_window(wndw->mlx, wndw->wndw, wndw->collectible, x, y);
	if (c == 'E')
		mlx_put_image_to_window(wndw->mlx, wndw->wndw, wndw->door, x, y);
	if (c == 'P')
	{
		wndw->plyr->x = x;
		wndw->plyr->y = y;
		mlx_put_image_to_window(wndw->mlx, wndw->wndw, wndw->plyr->img, x, y);
	}
}

void	change_map(t_wndw *wndw)
{
	int	i;
	int	j;
	int	x;
	int	y;

	i = -1;
	y = 0;
	while (wndw->map->inside[++i])
	{
		j = 0;
		x = 0;
		while (wndw->map->inside[i][j])
		{
			put_img(wndw->map->inside[i][j++], wndw, x, y);
			x += 73;
		}
		y += 73;
	}
}
