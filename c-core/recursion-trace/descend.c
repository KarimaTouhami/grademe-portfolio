void	descend(int n, void (*on_enter)(int), void (*on_leave)(int))
{
	if (n <= 0)
		return ;
	if (on_enter)
		on_enter(n);
	descend(n - 1, on_enter, on_leave);
	if (on_leave)
		on_leave(n);
}