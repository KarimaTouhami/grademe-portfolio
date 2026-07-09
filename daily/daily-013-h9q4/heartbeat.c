int	bytes_to_echo(int requested, int received)
{
	if (requested >= 0 && requested <= received)
		return (requested);
	return(0);
}
