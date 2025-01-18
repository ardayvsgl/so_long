#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
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
		total = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1));
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
