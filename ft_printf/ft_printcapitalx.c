#include "ft_printf.h"

static int	digit_number(unsigned int n)
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

int	ft_printcapitalx(unsigned int d)
{
	int	a;

	if (d < 16 && d >= 0)
		ft_printc("0123456789ABCDEF"[d]);
	else
	{
		ft_printcapitalx(d / 16);
		ft_printcapitalx(d % 16);
	}
	a = digit_number(d);
	return (a);
}
