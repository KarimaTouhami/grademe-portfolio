int	cmp_mixed(int a, unsigned int b)
{
	if (a < 0)
		return (-1);
	if ((unsigned int)a < b)
		return (-1);
	if ((unsigned int)a > b)
		return (1);
	return (0);
}
