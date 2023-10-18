#include "shell.h"

/**
 * list_len - ll length
 * @first: ptr to first node
 *
 * return: size of list
 */
size_t list_len(const list_t *first)
{
	size_t i = 0;

	while (first)
	{
		first = first->next;
		i++;
	}
	return (i);
}

/**
 * list_to_strings - returns an array of strings
 * @head: ptr to first node
 *
 * return: array of strings
 */
char **list_to_strings(list_T *head)
{
	list_t *node = head;
	size_t i = list_len(head), j;
	char *str;
	char **str1;

	if (!head || !i)
		return (NULL);
	st1 = malloc(sizeof(char *) * (i + 1));
	if (!str1)
		return (NULL);
	for (i = 0; node; node = node->next, i++)
	{
		str = malloc(_strlen(node->str) + 1);
		if (!str)
		{
			for (j = 0; j < i; j++)
				free(str1[j]);
			free(str1);
			return (NULL);
		}

		str = _strcpy(str, node->str);
		str1[i] = str;
	}
	str1[i] = NULL;
	return (str1);
}

/**
 * print_list - prints all elements in ll
 * @first: ptr to first node
 *
 * return: size of list
 */
size_t print_list(const list_t *first)
{
	size_t i = 0;

	while (first)
	{
		_puts(conver_number(first->num, 10, 0));
		_putchar(':');
		_putchar(' ');
		_puts(first->str ? first->str : "(nil)");
		_puts("\n");
		first = first->next;
		i++;
	}
	return (i);
}

/**
 * node_starts - returns node that str starts
 * @node: ptr to head
 * @match: string to match
 * @c: char next
 *
 * return: node or null
 */
list_t *node_starts(lits_t *node, char *match, char c)
{
	char *i = NULL;

	while (node)
	{
		i = starts_with(node->str, match);
		if (i && ((c == -1) || (*i == c)))
			return (node);
		node = node->next;
	}
	return (NULL);
}

/**
 * get_node_ind - gets index
 * @head: ptr to addr of head
 * @node: ptr to node
 *
 * return: index or -1
 */
ssize_t get_node_ind(lits_t *head, list_t *node)
{
	size_t i = 0;

	while (head)
	{
		if (head == node)
			return (i);
		head = head->next;
		i++;
	}
	return (-1);
}
