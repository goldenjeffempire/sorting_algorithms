#include "sort.h"

/**
 * swap_nodes - Swaps two nodes in a doubly linked list.
 * @list: Pointer to the head of the list.
 * @node1: Pointer to the first node.
 * @node2: Pointer to the second node.
 * Return: Void.
 */
void swap_nodes(listint_t **list, listint_t **node1, listint_t *node2)
{
	(*node1)->next = node2->next;
	if (node2->next != NULL)
	{
		node2->next->prev = *node1;
	}
	node2->prev = (*node1)->prev;
	node2->next = *node1;
	if ((*node1)->prev != NULL)
	{
		(*node1)->prev->next = node2;
	}
	else
	{
		*list = node2;
	}
	(*node1)->prev = node2;
	*node1 = node2->prev;
}
/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 *                       in ascending order using Insertion sort.
 * @list: Pointer pointing to the list.
 * Return: Void.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *temp, *before;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (current = (*list)->next; current != NULL; current = temp)
	{
		temp = current->next;
		before = current->prev;
		while (current->prev != NULL && current->n < before->n)
		{
			swap_nodes(list, &before, current);
			print_list((const listint_t *)*list);
		}
	}
}
