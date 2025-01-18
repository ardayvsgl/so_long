#include "so_long_bonus.h"

void	collectible_control(t_wndw *wndw)
{
	int	i;
	int	j;

	i = -1;
	while (wndw->map->inside[++i])
	{
		j = 0;
		while (wndw->map->inside[i][j++])
		{
			if (wndw->map->inside[i][j] == 'C')
			{
				wndw->map->count_c += 1;
				wndw->map->validc += 1;
			}
		}
	}
	if (wndw->map->count_c <= 0)
	{
		ft_printf("Error\nnot found collectible");
		close_all(wndw);
	}
}

void	file_control(char *path)
{
	int	fd;

	fd = open(path, O_RDWR);
	if (fd < 0)
	{
		ft_printf("Error\nWrong File Path");
		close(fd);
		exit(1);
	}
	close(fd);
}

void	char_control(t_wndw *wndw)
{
	int	i;
	int	j;

	i = -1;
	while (wndw->map->inside[++i])
	{
		j = -1;
		while (wndw->map->inside[i][++j])
		{
			if (wndw->map->inside[i][j] != '0' && wndw->map->inside[i][j] != '1'
			&& wndw->map->inside[i][j] != 'P' && wndw->map->inside[i][j] != 'C'
			&& wndw->map->inside[i][j] != 'E' && wndw->map->inside[i][j] != 'W')
			{
				ft_printf("Error\nUndefined Char");
				close_all(wndw);
			}
		}
	}
}

void	ft_validmap_check(t_wndw *wndw, int x, int y)
{
	if (wndw->map->tmp_map[y / 73][x / 73] == 'E')
		wndw->map->validdoor = 1;
	if (wndw->map->tmp_map[y / 73][x / 73] != 'E'
	&& wndw->map->tmp_map[y / 73][x / 73] != '1')
	{
		if (wndw->map->tmp_map[y / 73][x / 73] == 'C')
			wndw->map->validc--;
			wndw->map->tmp_map[y / 73][x / 73] = '.';
		if (wndw->map->tmp_map[y / 73][(x / 73) + 1] != '1' &&
			wndw->map->tmp_map[y / 73][(x / 73) + 1] != '.')
			ft_validmap_check(wndw, x + 73, y);
		if (wndw->map->tmp_map[y / 73][(x / 73) - 1] != '1' &&
			wndw->map->tmp_map[y / 73][(x / 73) - 1] != '.')
			ft_validmap_check(wndw, x - 73, y);
		if (wndw->map->tmp_map[(y / 73) - 1][x / 73] != '1' &&
			wndw->map->tmp_map[(y / 73) - 1][x / 73] != '.')
			ft_validmap_check(wndw, x, y - 73);
		if (wndw->map->tmp_map[(y / 73) + 1][x / 73] != '1' &&
			wndw->map->tmp_map[(y / 73) + 1][x / 73] != '.')
			ft_validmap_check(wndw, x, y + 73);
	}
}

void	ft_path_check(t_wndw *wndw)
{
	int	i;

	i = 0;
	while (wndw->map->tmp_map[i])
	{
		free(wndw->map->tmp_map[i]);
		i++;
	}
	free(wndw->map->tmp_map);
	if (wndw->map->validdoor != 1)
	{
		ft_printf("Error\ndoor is not reachable");
		exit(1);
	}
	if (wndw->map->validc != 0)
	{
		ft_printf("Error\ncollectible is not reachable");
		exit(1);
	}
}
