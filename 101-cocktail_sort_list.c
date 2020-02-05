#include "sort.h"

/**
* cocktail_sort_list - sorts a doubly linked list in ascending order
* @list : dobly linked list
*/

void cocktail_sort_list(listint_t **list)
{
	listint_t *temp, *head;
	int state = 1;

	if (list == NULL)
		return;
	head = *list;
	while(state == 1)
	{
	while (head->next != NULL)
	{
		if (head->n > head->next->n)
		{
			state = 1;
			temp = head->next;
			if (head->prev != NULL)
				head->prev->next = temp;
			if (temp->next != NULL)
				temp->next->prev = head;
 			temp->prev = head->prev;
			head->next = temp->next;
                temp->next = head;
                if (head->prev == NULL)
                    *list = temp;
                head->prev = temp;
            }
            head = temp->next;
		}
        print_list(*list);
        state = 0;
        while (head->prev != NULL)
        {
            if (head->prev->n > head->n)
            {
                state = 1;
                temp = head->prev;
                if (temp->prev != NULL)
                    temp->prev->next = head;
                if (head->next != NULL)
                    head->next->prev = temp;
                head->prev = temp->prev;
                temp->next = head->next;
                temp->prev = head;
                head->next = temp;
            }
            head = temp;
            head = head->prev;
            if (head->prev == NULL)
                *list = head;
            print_list(*list);
        }
    }
}
