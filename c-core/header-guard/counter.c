#include "counter.h"

void	counter_reset(counter *item)
{
	if (!item)
		return ;
	item->value = 0;
}

void	counter_add(counter *item, int amount)
{
	if (!item)
		return ;
	item->value += amount;
}

int	counter_value(const counter *item)
{
	if (!item)
		return (0);
	return (item->value);
}