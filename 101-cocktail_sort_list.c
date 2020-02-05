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
	while (state < 3)
	{
		while (head->next != NULL)
		{
            head = head->next;
        }
		print_list(*list);
		state++;
		while (head->prev != NULL)
		{
			if (head->prev->n > head->n)
			{
				
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
