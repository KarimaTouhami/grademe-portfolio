int	*find_int(int *first, int *last, int value)
{
	while (first < last)
	{
		if (*first == value)
			return (first);
		first++;
	}
	return (last);
}
