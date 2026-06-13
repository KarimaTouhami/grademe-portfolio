#include <stddef.h>

char	*find_any_char(const char *text, const char *needles)
{
	int	i;
	int	j;

	if (!text || !needles)
		return (NULL);
	i = 0;
	while (text[i] != '\0')
	{
		j = 0;
		while (needles[j] != '\0')
		{
			if (text[i] == needles[j])
			{
				return ((char *)&text[i]);
			}
			j++;
		}
		i++;
	}
	
	return (NULL);
}