#include <stddef.h>

char	*ft_strrchr(const char *s, int c)
{
	const char	*s_found;

	s_found = NULL;
	while (1)
	{
		if (*s == (char)c)
			s_found = s;
		if (*s == '\0')
			return ((char *)s_found);
		s++;
	}
}