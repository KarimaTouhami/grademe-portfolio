int	max(int *tab, unsigned int len)
{
	unsigned int	i;
	int				max_val;

	if (len == 0 || !tab)
		return (0);
	i = 1;
	max_val = tab[0];
	while (i < len)
	{
		if (tab[i] > max_val)
			max_val = tab[i];
		i++;
	}
	return (max_val);
}