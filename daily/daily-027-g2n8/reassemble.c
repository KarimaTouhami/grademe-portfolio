int	reassembled_ok(int offset, int len)
{
	if (offset +  len <= 65535)
		return(1);
	return (0);
}
