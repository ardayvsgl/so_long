#include "ft_printf.h"

static int	digit_number(unsigned int n)
{
	int	count;

	count = 1;
	if (n < 0)
	{
		count = 2;
		n = -n;
	}
	while (n > 9)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

int	ft_printu(unsigned int d)
{
	int	a;

	if (d < 10 && d >= 0)
		ft_printc('0' + d % 10);
	else
	{
		ft_printu(d / 10);
		ft_printc('0' + d % 10);
	}
	a = digit_number(d);
	return (a);
}
