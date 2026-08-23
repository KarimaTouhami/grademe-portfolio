int	backoff(const int *ok, int n)
{
	int	i;
	int		wait;

	wait = 1;
	i = 0;
	while (i < n)
	{
		if (ok[i] == 1)
			wait = 1;
		else
		{
			wait *= 2;
			if (wait > 32)
				wait = 32;
		}
		i++;
	}
	return (wait);
}