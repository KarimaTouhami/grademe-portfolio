static unsigned int	gcd_u(unsigned int a, unsigned int b)
{
	unsigned int	rem;

	while (b != 0)
	{
		rem = a % b;
		a = b;
		b = rem;
	}
	return (a);
}

unsigned int	lcm(unsigned int a, unsigned int b)
{
	if (a == 0 || b == 0)
		return (0);
	return ((a / gcd_u(a, b)) * b);
}