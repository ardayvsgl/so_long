#include "so_long.h"

void	xpm_control(void)
{
	int	fd1;
	int	fd2;
	int	fd3;
	int	fd4;

	fd1 = open("./pictures/c.xpm", O_RDWR);
	fd2 = open("./pictures/Door.xpm", O_RDWR);
	fd3 = open("./pictures/place.xpm", O_RDWR);
	fd4 = open("./pictures/p2.xpm", O_RDWR);
	if (fd1 < 0 || fd2 < 0 || fd3 < 0 || fd4 < 0)
	{
		ft_printf("Error\nMissing XPM File");
		close(fd1);
		close(fd2);
		close(fd3);
		close(fd4);
		exit(1);
	}
	close(fd1);
	close(fd2);
	close(fd3);
	close(fd4);
}

void	xpm_cntrl(void)
{
	int	fd1;

	fd1 = open("./pictures/w.xpm", O_RDWR);
	if (fd1 < 0)
	{
		ft_printf("Error\nMissing XPM File");
		close(fd1);
		exit(1);
	}
	close(fd1);
}

void	path_checker(char *path)
{
	int	len;

	len = ft_strlen(path);
	if (path[len - 4] != '.' || path[len - 3] != 'b'
		|| path[len - 2] != 'e' || path[len - 1] != 'r')
	{
		ft_printf("Error\nWrong File Extension");
		exit(1);
	}
}

void	endln_control(char line)
{
	if (line == '\n')
	{
		ft_printf("Error\nempty line");
		exit(1);
	}
}
