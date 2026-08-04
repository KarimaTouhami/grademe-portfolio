int	money_format(long cents, char *out)
{
	unsigned long	u;
	char			tmp[24];
	int				len;
	int				i;

	u = cents;
	if (cents < 0)
		u = -u;
	tmp[0] = '0' + (u % 10);
	u = u / 10;
	tmp[1] = '0' + (u % 10);
	u = u / 10;
	tmp[2] = '.';
	tmp[3] = '0' + (u % 10);
	u = u / 10;
	len = 4;
	while (u > 0)
	{
		tmp[len] = '0' + (u % 10);
		u = u / 10;
		len++;
	}
	if (cents < 0)
	{
		tmp[len] = '-';
		len++;
	}
	i = 0;
	while (i < len)
	{
		out[i] = tmp[len - 1 - i];
		i++;
	}
	out[i] = '\0';
	return (len);
}