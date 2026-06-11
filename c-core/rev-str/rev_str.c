char	*rev_str(char *str)
{
	int		i = -1;
	int		j = 0;
	char	t;

	while (str[j])
		j++;
	while (++i < --j)
	{
		t = str[i];
		str[i] = str[j];
		str[j] = t;
	}
	return (str);
}