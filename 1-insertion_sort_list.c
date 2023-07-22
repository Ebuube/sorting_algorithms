#include "sort.h"
#include <stdio.h>
#include <limits.h>

listint_t *swap(listint_t *node, listint_t **list);

/**
 * insertion_sort_list - sorts a doubly linked listint_t list of integers
 * in ascending order using Insertion sort algorithm.
 * @list: Address of head of the list
 *
 * Description: The list is printed each time a swap is performed
 * Return: nothing
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *cur = NULL, *list_pos = NULL;

	if (list == NULL || (*list)->next == NULL)
	{
		return;
	}
	list_pos = (*list)->next;

	while (list_pos != NULL)
	{
		printf("*list = %p\t(*list)->n = %d\t|\tlist_pos = %p\tlist_pos->n = %d\t|\tlist_pos->prev = %p\tlist_pos->prev->n %d\n",
			(void *)(*list), (*list)->n,
			(void *)list_pos, list_pos->n,
			(void *)list_pos->prev, (list_pos->prev != NULL) ? list_pos->prev->n : INT_MIN);
		if (list_pos->n < list_pos->prev->n)
		{
			cur = list_pos;
			while(cur->prev != NULL)
			{
				if (cur->n < cur->prev->n)
				{/* disorder found: swap nodes */
					cur = swap(cur, list);

					print_list(*list);
				}
				else
					cur = cur->prev;
			}
			*list = cur;
		}
		list_pos = list_pos->next;
	}
}


/**
 * swap - swap a node with its previous node
 * @node: pointer to the node to swap
 * @list: head pointer to the list
 *
 * Return: pointer to the node swapped if successful,
 * else return NULL
 */
listint_t *swap(listint_t *node, listint_t **list)
{
	listint_t *back = NULL, *front = NULL;

	if (node == NULL || node->prev == NULL)
	{
		return (NULL);
	}
	back = node->prev;
	front = node->next;

	if (back->prev != NULL)
		back->prev->next = node;
	back->next = front;
	if (front != NULL)
		front->prev = back;
	node->prev = back->prev;
	back->prev = node;
	node->next = back;

	if (node->prev == NULL)
		(*list) = node;

	return (node);
}
