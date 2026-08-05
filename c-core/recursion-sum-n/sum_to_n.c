int	sum_to_n(int n)
{
	if (n < 0)
		return (-1);
	if (n == 0)
		return (0);
	return (n + sum_to_n(n - 1));
}