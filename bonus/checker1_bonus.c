#include "so_long_bonus.h"

void	player_control(t_wndw *wndw)
{
	int	i;
	int	j;

	i = 0;
	while (wndw->map->inside[i])
	{
		j = 0;
		while (wndw->map->inside[i][j])
		{
			if (wndw->map->inside[i][j] == 'P')
				wndw->map->count_p += 1;
			j++;
		}
		i++;
	}
	if (wndw->map->count_p != 1)
	{
		ft_printf("Error\nplayer count error");
		close_all(wndw);
	}
}

void	wall_control(t_wndw *wndw)
{
	int	i;

	i = -1;
	while (wndw->map->inside[0][++i])
	{
		if (wndw->map->inside[0][i] != '1' ||
			wndw->map->inside[wndw->map->height - 1][i] != '1')
		{
			ft_printf("Error\nwall error");
			close_all(wndw);
		}
	}
	i = -1;
	while (wndw->map->inside[++i])
	{
		if (wndw->map->inside[i][0] != '1' ||
		wndw->map->inside[i][wndw->map->width - 1] != '1')
		{
			ft_printf("Error\nwall error");
			close_all(wndw);
		}
	}
}

void	map_size_control(t_wndw *wndw)
{
	int	i;

	i = 0;
	while (wndw->map->inside[i])
	{
		if (ft_strlen(wndw->map->inside[i]) != wndw->map->width)
		{
			ft_printf("Error\nline size error");
			close_all(wndw);
		}
		i++;
	}
}

void	door_control(t_wndw *wndw)
{
	int	i;
	int	j;

	i = -1;
	while (wndw->map->inside[++i])
	{
		j = 0;
		while (wndw->map->inside[i][j++])
		{
			if (wndw->map->inside[i][j] == 'E')
				wndw->map->count_e += 1;
		}
	}
	if (wndw->map->count_e < 1)
	{
		ft_printf("Error\ndoor count error");
		close_all(wndw);
	}
}
