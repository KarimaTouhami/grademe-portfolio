unsigned char	reverse_bits(unsigned char octet)
{
	int				i;
	unsigned char	result;

	i = 0;
	result = 0;
	while (i < 8)
	{
		result = (result << 1) | (octet & 1);
		octet = octet >> 1;
		i++;
	}
	return (result);
}