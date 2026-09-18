void	reverse_int(int *a, int n)
{
	int	start;
	int	end;
	int	tmp;

	if (!a || n <= 1)
		return ;
	start = 0;
	end = n - 1;
	while (start < end)
	{
		tmp = a[start];
		a[start] = a[end];
		a[end] = tmp;
		start++;
		end--;
	}
}
