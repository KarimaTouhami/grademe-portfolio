char	*strcpy(char *dst, const char *src)
{
	char *save;

	save = dst;
	while ((*dst++ = *src++) != '\0')
		;
	return (save);
}