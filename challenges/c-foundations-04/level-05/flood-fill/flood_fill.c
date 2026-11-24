typedef struct s_point
{
	int	x;
	int	y;
}	Point;

static void	fill(char **tab, Point size, int x, int y, char target)
{
	if (x < 0 || y < 0 || x >= size.x || y >= size.y)
		return ;
	if (tab[y][x] != target)
		return ;
	tab[y][x] = 'F';
	fill(tab, size, x + 1, y, target);
	fill(tab, size, x - 1, y, target);
	fill(tab, size, x, y + 1, target);
	fill(tab, size, x, y - 1, target);
}

void	flood_fill(char **tab, Point size, Point begin)
{
	char	target;

	target = tab[begin.y][begin.x];
	if (target != 'F')
		fill(tab, size, begin.x, begin.y, target);
}