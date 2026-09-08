int	flat_rows(const int *net, int w, int h)
{
	int r;
	int c;
	int		count;
	int 	full;

	count = 0;
	r = 0;
	while (r < h)
	{
		full = 1;
		c = 0;
		while (c < w)
		{
			if (net[r * w + c] == 0)
			{
				full = 0;
				break ;
			}
			c++;
		}
		if (full)
			count++;
		r++;
	}
	return (count);
}
