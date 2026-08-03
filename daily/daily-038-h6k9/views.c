int	displayed_views(long real)
{
	long long mod;
	mod = real % 4294967296LL;
	if (mod <= 2147483648)
		mod -= 4294967296LL;
	return ((int)mod);
}
