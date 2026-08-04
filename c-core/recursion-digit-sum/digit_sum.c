static int	my_abs(int val)
{
	if (val < 0)
		return (-val);
	return (val);
}

int	digit_sum(int n)
{
	if (n == 0)
		return (0);
	return (my_abs(n % 10) + digit_sum(n / 10));
}