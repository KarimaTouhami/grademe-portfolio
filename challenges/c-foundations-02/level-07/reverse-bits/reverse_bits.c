unsigned char	reverse_bits(unsigned char byte)
{
	int	i;
	unsigned char	res;

	i = 8;
	res = 0;
	while (i > 0)
	{
		res = (res << 1);
		res = res | (byte & 1);
		byte = (byte >> 1);
		i--;
	}
	return (res);
}