typedef struct	s_point
{
	int			x;
	int			y;
}				t_point;

void	fill(char **tab, t_point size, t_point cur, char target)
{
	t_point	next;

	if (cur.x < 0 || cur.x >= size.x || cur.y < 0 || cur.y >= size.y)
		return ;
	if (tab[cur.y][cur.x] != target)
		return ;
	tab[cur.y][cur.x] = 'F';
	next.x = cur.x;
	next.y = cur.y - 1;
	fill(tab, size, next, target);
	next.x = cur.x;
	next.y = cur.y + 1;
	fill(tab, size, next, target);
	next.x = cur.x - 1;
	next.y = cur.y;
	fill(tab, size, next, target);
	next.x = cur.x + 1;
	next.y = cur.y;
	fill(tab, size, next, target);
}

void	flood_fill(char **tab, t_point size, t_point begin)
{
	char	target;

	target = tab[begin.y][begin.x];
	if (target == 'F')
		return ;
	fill(tab, size, begin, target);
}