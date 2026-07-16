int	counter_ok(long centiseconds)
{
	if (centiseconds >= 0 && centiseconds <= 2147483647)
		return (1);
	return (0);
}
