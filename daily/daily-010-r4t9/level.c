// The level counter is one byte, so it wraps at 256. Return the value it shows
// (level modulo 256). If that wraps to 0, that is the kill screen: return -1.
int	displayed_level(int level)
{
	int	res;

	res = level % 256;
	if (res == 0)
		return (-1);
	return (res);
}
