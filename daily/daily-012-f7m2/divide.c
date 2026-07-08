// table[d - 1] should equal 840 / d for d in 1..8 (all divide evenly).
// Three entries are wrong. Fix the values, nothing else.
int	divide_840(int d)
{
	static const int	table[8] = {840, 420, 280, 210, 168, 140, 120, 105};

	if (d<1 || d>8)
		return (0);
	return (table[d - 1]);
}
