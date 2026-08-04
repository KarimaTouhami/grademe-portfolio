int	is_leap_year(int year)
{
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
		return (1);
	return (0);
}

int	days_in_month(int year, int month)
{
	if (month < 1 || month > 12)
		return (-1);
	if (month == 2)
	{
		if (is_leap_year(year))
			return (29);
		return (28);
	}
	if (month == 4 || month == 6 || month == 9 || month == 11)
		return (30);
	return (31);
}