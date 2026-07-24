int	excel_mangles(const char *name)
{
	char *m[] = {"JAN", "FEB", "MAR", "APR", "MAY", "JUN",
				"JUL", "AUG", "SEP", "OCT", "NOV", "DEC"};
	int	i = 0;
	int j;
	while (i <12)
	{
		j = 0;
		while (j <3 && name[j] == m[i][j])
			j++;
		if (j == 3)
		{
			if (name[3] <'0' || name[3] > '9')
				return (0);
			while (name[j]>= '0' && name[j] <= '9')
				j++;
			return (name[j] == '\0');
		}
		i++;
	}
	return (0);
}