#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H
# include <fcntl.h>
# include <stdlib.h>
# include "../mlx/mlx.h"
# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"
# include "../gnl/get_next_line.h"

typedef struct s_plyr {
	int		x;
	int		y;
	int		point;
	void	*img1;
	void	*img2;
	void	*img3;
}	t_plyr;

typedef struct s_enmy {
	int		x;
	int		y;
	void	*img1;
	void	*img2;
	void	*img3;
}	t_enmy;

typedef struct s_map {
	char	**inside;
	char	**tmp_map;
	int		height;
	int		width;
	int		validdoor;
	int		validc;
	int		count_c;
	int		count_p;
	int		count_e;
}	t_map;

typedef struct s_wndw {
	t_plyr	*plyr;
	t_enmy	*enmy;
	t_map	*map;
	int		height;
	int		width;
	void	*mlx;
	void	*wndw;
	void	*wall;
	void	*door;
	void	*collectible;
	void	*place;
}	t_wndw;

void	player_control(t_wndw *wndw);
void	wall_control(t_wndw *wndw);
void	map_size_control(t_wndw *wndw);
void	door_control(t_wndw *wndw);
void	xpm_control(void);
void	xpm_cntrl(void);
void	xpm_cntrl2(void);
void	path_checker(char *path);
void	endln_control(char line);
void	collectible_control(t_wndw *wndw);
void	file_control(char *path);
void	char_control(t_wndw *wndw);
char	*read_file(char	*path);
t_map	*read_map(char *path);
void	put_img(char c, t_wndw *wndw, int x, int y);
void	put_score(t_wndw *wndw);
void	change_map(t_wndw *wndw);
void	move_map(t_wndw *wndw, int side, int x, int y);
int		close_all(void *param);
int		move_plyr(int keycode, void *param);
void	get_img(t_wndw *wndw, int x, int y);
void	ft_validmap_check(t_wndw *wndw, int x, int y);
void	ft_path_check(t_wndw *wndw);
void	open_windows(t_wndw *wndw, char *path);
int		fix_image(t_wndw *wndw);
void	do_sprite1(t_wndw *wndw, t_enmy *enmy, int x, int y);
void	do_sprite2(t_wndw *wndw, t_plyr *plyr, int x, int y);
#endif
