#include "so_long.h"

void	get_img(t_wndw *wndw, int x, int y)
{
	wndw->height = wndw->map->height * 73;
	wndw->width = wndw->map->width * 73;
	wndw->mlx = mlx_init();
	wndw->wndw = mlx_new_window(wndw->mlx, wndw->width,
			wndw->height, "Red Riding Hood");
	wndw->plyr = ft_calloc(1, sizeof(t_plyr));
	wndw->plyr->x = 0;
	wndw->plyr->y = 0;
	wndw->plyr->point = 0;
	wndw->plyr->img = mlx_xpm_file_to_image(wndw->mlx,
			"./pictures/p2.xpm", &x, &y);
	wndw->wall = mlx_xpm_file_to_image(wndw->mlx,
			"./pictures/w.xpm", &x, &y);
	wndw->collectible = mlx_xpm_file_to_image(wndw->mlx,
			"./pictures/c.xpm", &x, &y);
	wndw->place = mlx_xpm_file_to_image(wndw->mlx,
			"./pictures/place.xpm", &x, &y);
	wndw->door = mlx_xpm_file_to_image(wndw->mlx,
			"./pictures/Door.xpm", &x, &y);
}

void	open_windows(t_wndw *wndw, char *path)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	wndw->map = read_map(path);
	get_img(wndw, x, y);
	player_control(wndw);
	map_size_control(wndw);
	wall_control(wndw);
	door_control(wndw);
	collectible_control(wndw);
	char_control(wndw);
}

int	main(int argc, char **argv)
{
	t_wndw	wndw;

	if (argc == 2)
	{
		xpm_control();
		xpm_cntrl();
		path_checker(argv[1]);
		file_control(argv[1]);
		open_windows(&wndw, argv[1]);
		change_map(&wndw);
		ft_validmap_check(&wndw, wndw.plyr->x, wndw.plyr->y);
		ft_path_check(&wndw);
		mlx_hook(wndw.wndw, 2, (1L << 0), move_plyr, &wndw);
		mlx_hook(wndw.wndw, 17, 0, close_all, &wndw);
		mlx_loop(wndw.mlx);
	}
	else
	{
		ft_printf("Error\nmissing argument");
	}
	return (0);
}
