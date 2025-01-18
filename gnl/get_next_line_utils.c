#include "get_next_line.h"

char	*ft_strjoin2(char const *s1, char const *s2)
{
	char	*total;
	size_t	i;
	size_t	j;

	if (!s1 && !s2)
		return (NULL);
	else if (!s1)
		return ((char *)s2);
	else if (!s2)
		return ((char *)s1);
	else
	{	
		i = 0;
		j = 0;
		total = (char *)malloc((ft_strlen2(s1) + ft_strlen2(s2) + 1));
		if (!total)
			return (NULL);
		while (s1[j])
			total[i++] = s1[j++];
		j = 0;
		while (s2[j])
			total[i++] = s2[j++];
		total[i] = '\0';
	}
	return (total);
}

char	*ft_strchr2(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)(s + i));
	return (NULL);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	a;

	a = 0;
	while (a < n)
	{
		((unsigned char *)s)[a] = 0;
		a++;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	size_t	tot_size;
	void	*dst;

	tot_size = size * count;
	dst = malloc(tot_size);
	if (!(dst))
		return (0);
	ft_bzero(dst, tot_size);
	return (dst);
}

int	ft_strlen2(const char *a)
{
	int	i;

	i = 0;
	while (a[i])
		i++;
	return (i);
}
