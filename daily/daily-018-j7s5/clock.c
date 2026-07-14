
int	is_leap(int year)
{
	return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}

int	year_from_days(int days)
{
	int	year;

	year = 1980;
	while (days > 365)
	{
		if (is_leap(year))
		{
			if (days > 366)
			{
				days -= 366;
				year++;
			} else {
				break ;
			}
		}
		else
		{
			days -= 365;
			year++;
		}
	}
	return (year);
}
