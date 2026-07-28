int	safe_copy(char *dst, int cap, const char *src)
{
	int	i;
	if (cap <= 0)
		return (0);

	i = 0;
	while (src[i] && (i < cap - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (i);
}
