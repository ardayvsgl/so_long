#include "ft_printf.h"

static int	digit_number(unsigned long long n)
{
	int	count;

	count = 1;
	while (n > 15)
	{
		n = n / 16;
		count++;
	}
	return (count);
}

static int	ft_printxp(unsigned long long d)
{
	int	a;

	if (d < 16 && d >= 0)
		ft_printc("0123456789abcdef"[d]);
	else
	{
		ft_printxp(d / 16);
		ft_printxp(d % 16);
	}
	a = digit_number(d);
	return (a);
}

int	ft_printp(unsigned long long d)
{
	int	a;

	ft_prints("0x");
	a = 2 + ft_printxp((unsigned long long)d);
	return (a);
}
