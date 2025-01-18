#include "libft.h"

static int	digit_number(int n)
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

char	*ft_itoa(int n)
{
	char	*str;
	int		counter;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	counter = digit_number(n);
	str = (char *)malloc((counter + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[counter] = '\0';
	counter--;
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	while (n > 0)
	{
		str[counter--] = (n % 10) + 48;
		n = n / 10;
	}
	return (str);
}
