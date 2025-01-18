#include "so_long_bonus.h"

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

void	do_sprite2(t_wndw *wndw, t_plyr *plyr, int x, int y)
{
	static int	i;

	if (i > 0 && i < 10)
		mlx_put_image_to_window(wndw->mlx, wndw->wndw, plyr->img1, x, y);
	if (i >= 10 && i < 20)
		mlx_put_image_to_window(wndw->mlx, wndw->wndw, plyr->img2, x, y);
	if (i >= 20 && i < 30)
		mlx_put_image_to_window(wndw->mlx, wndw->wndw, plyr->img3, x, y);
	if (i >= 30 && i < 40)
		mlx_put_image_to_window(wndw->mlx, wndw->wndw, plyr->img2, x, y);
	if (i == 40)
		i = 0;
	i++;
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
	if (c == 'W')
	{
		wndw->enmy->x = x;
		wndw->enmy->y = y;
		do_sprite1(wndw, wndw->enmy, x, y);
	}
	if (c == 'P')
	{
		wndw->plyr->x = x;
		wndw->plyr->y = y;
		do_sprite2(wndw, wndw->plyr, x, y);
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
			put_score(wndw);
			x += 73;
		}
		y += 73;
	}
}
