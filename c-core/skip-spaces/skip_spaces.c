const char	*skip_spaces(const char *s)
{
	while (*s == ' ' || *s == '\t')
		s++;
	return ((char *)s);
}
