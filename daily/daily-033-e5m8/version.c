int	mail_flows(int yy, int mm, int dd, int hh, int mn)
{
	long	version;

	version = (long)yy;
	version = version * 100 + mm;
	version = version * 100 + dd;
	version = version * 100 + hh;
	version = version * 100 + mn;
	if (version <= 2147483647)
		return (1);
	return (0);
}