#include "ft_printf.h"

int	ft_prints(char *s)
{
	int	a;
	int	l;

	a = 0;
	l = 0;
	if (s == NULL)
	{
		ft_prints("(null)");
		return (6);
	}
	while (s[a])
	{
		write(1, &s[a++], 1);
		l++;
	}
	return (l);
}
