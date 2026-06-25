#include "list.h"
#include <stddef.h>

int	detect_cycle(ListNode *list)
{
	if (list == NULL || list->next == NULL)
		return (0);

	ListNode *slow = list;
	ListNode *fast = list;

	while (fast != NULL && fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast)
			return (1);
	}

	return (0);
}