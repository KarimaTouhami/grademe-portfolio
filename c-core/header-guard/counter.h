#ifndef COUNTER_H
# define COUNTER_H

typedef struct s_counter
{
	int	value;
}	counter;

void	counter_reset(counter *item);
void	counter_add(counter *item, int amount);
int	counter_value(const counter *item);
#endif