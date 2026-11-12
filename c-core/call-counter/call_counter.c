// next_id returns 1 on its first call, then 2, 3, and so on. After reset_ids,
// the next call to next_id returns 1 again.
static int	i; 
int	next_id(void)
{
	i++;
	return (i);
}

void	reset_ids(void)
{
	i = 0;
}
