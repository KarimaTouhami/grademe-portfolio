long	abs_safe(int n)
{
	long	val;
	val = (long)n;
	if (val < 0)
		return (-val);
	return (val);
}