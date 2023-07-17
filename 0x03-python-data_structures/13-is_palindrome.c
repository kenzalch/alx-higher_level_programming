#include "lists.h"

listint_t *reverse_listint(listint_t **head);
int is_palindrome(listint_t **head);

/**
 * reverse_listint - Reverses a singly-linked listint_t list.
 * @head: A pointer to the starting node of the list to reverse.
 *
 * Return: A pointer to the head of the reversed list.
 */
listint_t *reverse_listint(listint_t **head)
{
	listint_t *node = *head, *next, *prv = NULL;

	while (node)
	{
		next = node->next;
		node->next = prv;
		prv = node;
		node = next;
	}

	*head = prv;
	return (*head);
}

/**
 * is_palindrome - Checks if a singly linked list is a palindrome.
 * @head: A pointer to the head of the linked list.
 *
 * Return: If the linked list is not a palindrome - 0.
 *         If the linked list is a palindrome - 1.
 */
int is_palindrome(listint_t **head)
{
	listint_t *tm, *rv, *mid;
	size_t size = 0, i;

	if (*head == NULL || (*head)->next == NULL)
		return (1);

	tm = *head;
	while (tm)
	{
		size++;
		tm = tm->next;
	}

	tm = *head;
	for (i = 0; i < (size / 2) - 1; i++)
		tm = tm->next;

	if ((size % 2) == 0 && tm->n != tm->next->n)
		return (0);

	tm = tm->next->next;
	rv = reverse_listint(&tm);
	mid = rv;

	tm = *head;
	while (rv)
	{
		if (tm->n != rv->n)
			return (0);
		tm = tm->next;
		rv = rv->next;
	}
	reverse_listint(&mid);

	return (1);
}
