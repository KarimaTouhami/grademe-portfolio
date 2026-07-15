int	feb_days(int year)
{
	if ((year % 4 == 0) && (year % 100 != 0 || year % 400 == 0))
		return (29);
	return (28);
}
