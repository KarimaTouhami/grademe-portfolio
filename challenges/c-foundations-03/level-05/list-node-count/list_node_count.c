#include <stdlib.h>
typedef struct s_node
{
	void          *data;
	struct s_node *next;
}               t_node;

int	list_node_count(t_node *head)
{
	int		count;
	t_node	*current;

	count = 0;
	current = head;
	while (current != NULL)
	{
		count++;
		current = current->next;
	}
	return (count);
}