#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	index;

	if (!s)
		return (0);
	if (start < 0 || start > ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s))
		str = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	else
		str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	index = 0;
	while (index < len && start < ft_strlen(s))
		str[index++] = s[start++];
	str[index] = '\0';
	return (str);
}
