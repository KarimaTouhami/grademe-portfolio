#include "list.h"
#include <stddef.h>

void	list_apply(t_list *list, void (*f)(void *))
{
	t_list	*current;

	if (!list || !f)
		return ;
	current = list;
	while (current != NULL)
	{
		(*f)(current->data);
		current = current->next;
	}
}