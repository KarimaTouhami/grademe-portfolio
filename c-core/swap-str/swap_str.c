void	swap_str(char **a, char **b)
{
	char *tmp;

	if (!a || !b)
        return ;
    tmp = *a;
    *a = *b;
    *b = tmp;
}
