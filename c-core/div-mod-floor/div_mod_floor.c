void	div_mod_floor(int a, int b, int *q, int *r)
{
	int	quot;
	int	rem;

	quot = a / b;
	rem = a % b;
	if (rem < 0)
	{
		if (b > 0)
		{
			quot -= 1;
			rem += b;
		}
		else
		{
			quot += 1;
			rem -= b;
		}
	}
	*q = quot;
	*r = rem;
}