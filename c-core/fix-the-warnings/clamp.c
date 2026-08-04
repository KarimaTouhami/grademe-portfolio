int	clamp(int v, int lo, int hi)
{
	if (lo > hi)
		return (lo);
	if (v < lo)
		return (lo);
	if (v > hi)
		return (hi);
	return (v);
}