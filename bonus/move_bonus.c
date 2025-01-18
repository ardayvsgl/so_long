#include "so_long_bonus.h"

void	move_map(t_wndw *wndw, int side, int x, int y)
{
	if (wndw->map->count_c == 0 && wndw->map->inside[y / 73][x / 73] == 'E')
	{
		wndw->plyr->point += 1;
		ft_printf("%d\n", wndw->plyr->point);
		ft_printf("Win!");
		close_all(wndw);
	}
	if (wndw->map->inside[y / 73][x / 73] == 'W')
	{
		ft_printf("%d\n", wndw->plyr->point);
		ft_printf("Lose!");
		close_all(wndw);
	}
	if (wndw->map->inside[y / 73][x / 73] != '1' &&
		wndw->map->inside[y / 73][x / 73] != 'E')
	{
		wndw->plyr->point += 1;
		if (wndw->map->inside[y / 73][x / 73] == 'C')
			wndw->map->count_c -= 1;
		wndw->map->inside[wndw->plyr->y / 73][wndw->plyr->x / 73] = '0';
		wndw->map->inside[y / 73][x / 73] = 'P';
		ft_printf("%d\n", wndw->plyr->point);
	}
}

int	close_all(void *param)
{
	t_wndw	*wndw;
	int		i;

	wndw = param;
	i = 0;
	mlx_destroy_image(wndw->mlx, wndw->plyr->img1);
	mlx_destroy_image(wndw->mlx, wndw->plyr->img2);
	mlx_destroy_image(wndw->mlx, wndw->plyr->img3);
	mlx_destroy_image(wndw->mlx, wndw->enmy->img1);
	mlx_destroy_image(wndw->mlx, wndw->enmy->img2);
	mlx_destroy_image(wndw->mlx, wndw->enmy->img3);
	mlx_destroy_image(wndw->mlx, wndw->collectible);
	mlx_destroy_image(wndw->mlx, wndw->door);
	mlx_destroy_image(wndw->mlx, wndw->place);
	mlx_destroy_image(wndw->mlx, wndw->wall);
	free(wndw->plyr);
	while (wndw->map->inside[i])
		free(wndw->map->inside[i++]);
	free(wndw->map->inside);
	free(wndw->map);
	mlx_destroy_window(wndw->mlx, wndw->wndw);
	exit(1);
	return (1);
}

int	move_plyr(int keycode, void *param)
{
	t_wndw	*wndw;

	wndw = param;
	mlx_clear_window(wndw->mlx, wndw->wndw);
	if (keycode == 2)
		move_map(wndw, keycode, wndw->plyr->x + 73, wndw->plyr->y);
	if (keycode == 0)
		move_map(wndw, keycode, wndw->plyr->x - 73, wndw->plyr->y);
	if (keycode == 13)
		move_map(wndw, keycode, wndw->plyr->x, wndw->plyr->y - 73);
	if (keycode == 1)
		move_map(wndw, keycode, wndw->plyr->x, wndw->plyr->y + 73);
	if (keycode == 53)
		close_all(wndw);
	change_map(wndw);
	return (keycode);
}

void	put_score(t_wndw *wndw)
{
	char	*score;

	score = ft_itoa(wndw->plyr->point);
	mlx_string_put(wndw->mlx, wndw->wndw, 25, 25, 0xFFFFFF, score);
	free(score);
}
