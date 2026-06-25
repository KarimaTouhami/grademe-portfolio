#include "list.h"
#include <stddef.h>

ListNode *sort_list(ListNode *lst, int (*cmp)(int, int))
{
    ListNode *i;
    ListNode *j;
    int temp;

    if (!lst)
        return (NULL);

    i = lst;
    while (i != NULL)
    {
        j = i->next;
        while (j != NULL)
        {
            if (cmp(i->data, j->data) == 0)
            {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
            j = j->next;
        }
        i = i->next;
    }
    return (lst);
}