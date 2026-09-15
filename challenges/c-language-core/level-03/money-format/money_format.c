int	money_format(long cents, char *out)
{
	char	buf[32];
	int		len;
	int		i;
	int		is_neg;
	long	rem;

	is_neg = (cents < 0);
	len = 0;
	while (1)
	{
		rem = cents % 10;
		buf[len++] = (char)('0' + (rem < 0 ? -rem : rem));
		cents /= 10;
		if (cents == 0)
			break ;
	}
	while (len < 3)
		buf[len++] = '0';
	i = 0;
	if (is_neg)
		out[i++] = '-';
	while (len > 2)
		out[i++] = buf[--len];
	out[i++] = '.';
	out[i++] = buf[1];
	out[i++] = buf[0];
	out[i] = '\0';
	return (i);
}
