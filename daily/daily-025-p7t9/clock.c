int	survives(int days_from_epoch, int tz_offset_hours)
{
	long long local_seconds;

	local_seconds = ((long long)days_from_epoch * 86400LL) + ((long long)tz_offset_hours * 3600LL);
	if (local_seconds >= 0)
		return (1);
	return (0);
}