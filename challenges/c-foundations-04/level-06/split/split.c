#include <stdlib.h>

static int	is_delimiter(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i] != '\0')
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

static int	count_words(char *str, char *charset)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		while (str[i] != '\0' && is_delimiter(str[i], charset))
			i++;
		if (str[i] != '\0' && !is_delimiter(str[i], charset))
		{
			count++;
			while (str[i] != '\0' && !is_delimiter(str[i], charset))
				i++;
		}
	}
	return (count);
}

static char	*copy_word(char *str, char *charset, int *index)
{
	int		start;
	int		len;
	int		i;
	char	*word;

	while (str[*index] != '\0' && is_delimiter(str[*index], charset))
		(*index)++;
	start = *index;
	len = 0;
	while (str[*index] != '\0' && !is_delimiter(str[*index], charset))
	{
		len++;
		(*index)++;
	}
	word = (char *)malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = str[start + i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**split(char *str, char *charset)
{
	char	**result;
	int		words_count;
	int		i;
	int		str_index;

	words_count = count_words(str, charset);
	result = (char **)malloc(sizeof(char *) * (words_count + 1));
	if (!result)
		return (NULL);
	i = 0;
	str_index = 0;
	while (i < words_count)
	{
		result[i] = copy_word(str, charset, &str_index);
		i++;
	}
	result[i] = NULL;
	return (result);
}