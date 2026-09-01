int	replayed(const int *east, int en, const int *west, int wn)
{
	int i;
	int j;

	i = j = 0;
	while (i < en && j < wn)
	{
		if (east[i] == west[j])
			j++;
		i++;
	}
	return ((int)j);
}