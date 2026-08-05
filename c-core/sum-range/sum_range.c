int	sum_range(const int *first, const int *last)
{
	int 	total;

	total = 0;
	while (first <last)
	{
		total += *first;
		first++;
	}
	return (total);
}
