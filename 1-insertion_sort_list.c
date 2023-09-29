#include "sort.h"
/**
 * insertion_sort_list - sorts a double linked list
 * of integers in ascending order using the
 * insertion sort algorithm
 *
 * @list: linked list argument
 *
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *node = NULL;
	listint_t *temp = NULL;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	node = *list;
	node = node->next;
	while (node)
	{
		while (node->prev && node->n < (node->prev)->n)
		{
			temp = node;
			if (node->next)
				(node->next)->prev = temp->prev;
			(node->prev)->next = temp->next;
			node = node->prev;
			temp->prev = node->prev;
			temp->next = node;
			if (node->prev)
				(node->prev)->next = temp;
			node->prev = temp;
			if (temp->prev == NULL)
				*list = temp;
			/* Print the List */
			print_list(*list);
			node = node->prev;
		}
		node = node->next;
	}
}
