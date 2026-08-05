int	decoded_len(const char *s)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (s[i])
	{
		len++;
		if (s[i] == '\\' && s[i + 1] != '\0')
			i += 2;
		else
			i++;
	}
	return (len);
}
