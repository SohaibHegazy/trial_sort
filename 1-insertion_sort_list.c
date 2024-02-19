#include "sort.h"

/**
 * swap_list - function to swap DLList elements
 *
 * @elem1: pointer to first element to be swapped
 * @elem2: pointer to second element to be swapped
 *
 * Return: void
 */

void swap_list(listint_t *elem1, listint_t *elem2)
{
	if (elem1->prev != NULL)
		elem1->prev->next = elem2;
	if (elem2->next != NULL)
		elem2->next->prev = elem1;

	elem1->next = elem2->next;
	elem2->prev = elem1->prev;
	elem2->next = elem1;
	elem1->prev = elem2;
}

/**
 * insertion_sort_list - function to sort list using insertion
 *
 * @list: is the list to be sorted
 *
 * Return: Void
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *key, *temp;

	if (!list || !*list || !(*list)->next)
		return;

	key = (*list)->next;
	while (key)
	{
		temp = key;
		key = key->next;

		while (temp && temp->prev)
		{
			if (temp->n < temp->prev->n)
			{
				swap_list(temp->prev, temp);

				if (!temp->prev)
					*list = temp;
				print_list((const listint_t *)*list);
			}
			else
				temp = temp->prev;
		}
	}
}
