#include "list.h"
#include <stdlib.h>

void list_filter(ListNode **begin, void *ref, int (*cmp)(void *, void *))
{
	if (!begin || !*begin)
		return;

	ListNode *current;
	ListNode *tmp;

	while (*begin && cmp((*begin)->data, ref) == 0)
	{
		tmp = *begin;
		*begin = (*begin)->next;
		free(tmp);
	}

	current = *begin;
	while (current && current->next)
	{
		if (cmp(current->next->data, ref) == 0)
		{
			tmp = current->next;
			current->next = current->next->next;
			free(tmp);
		}
		else
		{
			current = current->next;
		}
	}
}