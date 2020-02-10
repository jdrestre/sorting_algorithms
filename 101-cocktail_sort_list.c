#include "sort.h"

/**
* swap_next - swap in next for sorts a doubly linked list
* @list : doubly linked list
* Return: return head
*/
listint_t *swap_next(listint_t **list)
{
	listint_t *temp, *head;

	head = *list;
	while (head->next != NULL)
	{
		if (head->n > head->next->n)
		{
			temp = head->next;
			if (head->prev != NULL)
				head->prev->next = temp;
			if (temp->next != NULL)
				temp->next->prev = head;
			temp->prev = head->prev;
			head->next = temp->next;
			head->prev = temp;
			temp->next = head;
			head = temp->next;
			print_list(*list);
		}
		else
		{
			head = head->next;
		}
	}
	return (head);
}

/**
* cocktail_sort_list - sorts a doubly linked list in ascending order
* @list : dobly linked list
*/

void cocktail_sort_list(listint_t **list)
{
	listint_t *temp, *head;
	int state = 1;

	if (list == NULL || *list == NULL)
		return;
	head = *list;
	if (head->next == NULL)
		return;
	while (state == 1)
	{
		head = swap_next(&head);
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
				head = temp->prev;
				if (head->prev == NULL)
					*list = head;
				print_list(*list);
			}
			else
				head = head->prev;
		}
	}
}
