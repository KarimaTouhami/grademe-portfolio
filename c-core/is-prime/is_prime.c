// Return 1 if n is a prime number, 0 otherwise.
// n is between -1000 and 100000.
int	is_prime(int n)
{
	int		start;

	start = 2;
	if (n < start)
		return (0);
	while (start < n)
	{
		if (n % start == 0)
			return (0);
		start++;
	}
	return (1);
}
