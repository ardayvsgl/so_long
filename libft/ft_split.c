#include "libft.h"

static int	word_counter(const char *s, char c)
{
	int	word;
	int	i;
	int	sw;

	word = 0;
	sw = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && sw == 0)
		{
			sw = 1;
			word++;
		}
		else if (s[i] == c)
			sw = 0;
		i++;
	}
	return (word);
}

static char	*word_create(char *s, char c)
{
	char	*str;
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	str = (char *)malloc(i + 1);
	i = 0;
	while (s[i] && s[i] != c)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	size_t	i;
	size_t	j;

	if ((!s && !c) || !s)
		return (NULL);
	i = word_counter(s, c);
	j = 0;
	split = (char **)malloc((i + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else if (s[i] != c)
		{
			split[j++] = word_create((char *)&s[i], c);
			while (s[i] != c && s[i])
				i++;
		}
	}
	split[j] = 0;
	return (split);
}
