#include "ft_printf.h"

static int	digit_number(long int n)
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

int	ft_printi(int d)
{
	int	a;

	if (d == -2147483648)
	{
		ft_printi(d / 10);
		ft_printc('8');
	}
	else if (d < 10 && d >= 0)
		ft_printc('0' + d % 10);
	else if (d < 0)
	{
		ft_printc('-');
		ft_printi(-d);
	}
	else
	{
		ft_printi(d / 10);
		ft_printc('0' + d % 10);
	}
	a = digit_number(d);
	return (a);
}
