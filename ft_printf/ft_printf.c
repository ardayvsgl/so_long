#include "ft_printf.h"

int	ft_format(va_list arg, int c)
{
	int	len;

	len = 0;
	if (c == 'i' || c == 'd')
		len += ft_printi(va_arg(arg, int));
	if (c == 'c')
		len += ft_printc(va_arg(arg, int));
	if (c == 's')
		len += ft_prints(va_arg(arg, char *));
	if (c == 'p')
		len += ft_printp(va_arg(arg, unsigned long long));
	if (c == 'u')
		len += ft_printu(va_arg(arg, unsigned int));
	if (c == 'x')
		len += ft_printx(va_arg(arg, unsigned int));
	if (c == 'X')
		len += ft_printcapitalx(va_arg(arg, unsigned int));
	if (c == '%')
		len += ft_printc('%');
	return (len);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	arg;
	int		len;

	i = 0;
	len = 0;
	va_start(arg, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			len += ft_format(arg, str[i + 1]);
			i++;
		}
		else
			len += ft_printc(str[i]);
		i++;
	}
	va_end(arg);
	return (len);
}
