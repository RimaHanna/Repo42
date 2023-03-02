#include "push_swap.h"

size_t	ft_strlen(const char *str)
{
	size_t i;

	i = 0;
	while(str[i])
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*dup;
	size_t	sizes;

	sizes = ft_strlen(s);
	i = 0;
	j = 0;
	while (((start + i) < sizes) && s[start + i] && j < len)
	{
		i++;
		j++;
	}
	dup = (char *)malloc(sizeof(char) * (j + 1));
	if (!dup)
		return (NULL);
	i = 0;
	while (i < j)
	{
		dup[i] = s[start + i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

static size_t	count_words(char const *s, char c)
{
	size_t	i;
	size_t	strcount;

	i = 0;
	strcount = 0;
	while (s[i])
	{
		if ((s[i] != c) && ((i == 0) || (s[i - 1] == c)))
			strcount++;
		i++;
	}
	return (strcount);
}

static size_t	ft_calculate_len(const char *s, char c, size_t i, size_t len)
{
	if ((s[i] != c) && ((i == 0) || (s[i - 1] == c)))
		len = 0;
	if (s[i] != c)
		len++;
	return (len);
}

char	**ft_fill_split(char **split, const char *s, char c)
{
	size_t	count;
	size_t	i;
	size_t	len;
	size_t	start;

	i = 0;
	count = 0;
	start = 0;
	len = 0;
	while (s[i])
	{
		len = ft_calculate_len(s, c, i, len);
		if ((s[i] != c) && ((i == 0) || (s[i - 1] == c)))
			start = i;
		if (((s[i] == c) || (s[i + 1] == '\0')) && (len > 0))
		{
			split[count++] = ft_substr(s, start, len);
			len = 0;
		}		
		i++;
	}	
	return (split);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	size_t	count;
	size_t	i;

	count = count_words(s, c);
	split = (char **)malloc(sizeof(char *) * (count + 1));
	if (!split)
		return (NULL);
	split = ft_fill_split(split, s, c);
	i = 0;
	while (i < count)
	{
		if (!split[i])
			split[i] = "";
		i++;
	}
	split[count] = NULL;
	return (split);
}
