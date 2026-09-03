#include <stdlib.h>
#include <stddef.h>

static int	is_sep(char c, char *charset)
{
	int	i;

	if (!charset)
		return (0);
	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

static int	count_words(char *str, char *charset)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] && is_sep(str[i], charset))
			i++;
		if (str[i])
			count++;
		while (str[i] && !is_sep(str[i], charset))
			i++;
	}
	return (count);
}

static char	*allocate_word(char *str, char *charset, int *index)
{
	char	*word;
	int		len;
	int		i;

	len = 0;
	while (str[*index + len] && !is_sep(str[*index + len], charset))
		len++;
	word = (char *)malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = str[*index + i];
		i++;
	}
	word[i] = '\0';
	*index += len;
	return (word);
}

char	**split(char *str, char *charset)
{
	char	**arr;
	int		i;
	int		f;

	if (!str)
		return (NULL);
	arr = (char **)malloc(sizeof(char *) * (count_words(str, charset) + 1));
	if (!arr)
		return (NULL);
	i = 0;
	f = 0;
	while (str[i])
	{
		while (str[i] && is_sep(str[i], charset))
			i++;
		if (!str[i])
			break ;
		arr[f] = allocate_word(str, charset, &i);
		if (!arr[f])
			return (NULL);
		f++;
	}
	arr[f] = NULL;
	return (arr);
}