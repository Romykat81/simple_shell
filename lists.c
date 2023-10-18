#include "shell.h"

/**
 * add_node - adds a node at start of ll
 * @head: ptr to addr of head node
 * @str: str field
 * @num: node index used by hist
 *
 * return:  size of list
 */
list_t *add_node(list_t **head, const char *str, int num)
{
	list_t *n_head;

	if (!head)
		return (NULL);
	n_head = malloc(sizeof(list_t));
	if (!n_head)
		return (NULL);
	_memset((void *)n_head, 0, sizeof(list_t));
	n_head->num = num;
	if (str)
	{
		n_head->str = _strdup(str);
		if (!n_head->str)
		{
			free(n_head);
			return (NULL);
		}
	}
	n_head->next = *head;
	*head = n_head;
	return (n_head);
}

/**
 * add_node_end - add node end
 * @head: addr to ptr of head
 * @str: string node
 * @num: node index
 *
 * return: size of list
 */
list_t *add_node_end(list_t *8head, const char *str, int num)
{
	list_t *n_node, *node;

	if (!head)
		return (NULL);

	node = *head;
	n_node = malloc(sizeof(list_t));
	if (!n_node)
		return (NULL);
	_memset((void *)n_node, 0 , sizeof(list_t));
	n_node->num = num;
	if (str)
	{
		n_node->str = _strdup(str);
		if (!n_node->str)
		{
			free(n_node);
			return (NULL);
		}
	}
	if (node)
	{
		while (node->next)
			node = node->next;
		node->next = new_node;
	}
	else
		*head = n_node;
	return (n_node);
}

/**
 * delete_node_at_index - deletes the node at the given index
 * @head: addr of ptr to first node
 * @index: index of node todelete
 *
 * return: 1 on success, 0 on failure
 */
int delete_node_at_index(list_t **head, unsigned int index)
{
	list_t *node, *p_node;
	unsigned int i = 0;

	if (!head || !*head)
		return (0);

	if (!index)
	{
		node = *head;
		*head = (*head)->next;
		freee(node->str);
		free(node);
		return (1);
	}
	node = *head;
	while(node)
	{
		if (i == index)
		{
			p_node->next = node->next;
			free(node->str);
			free(node);
			return (1);
		}
		i++;
		p_node = node;
		node = node->next;
	}
	return (0);
}

/**
 * free_list - frees node of list
 * @head addr of ptr to head
 *
 * return: void
 */
void free_list(list_t **head)
{
	list_t *node, *next, *hhead;

	if (!head || !*head)
		return;
	hhead = *head;
	node = head;
	while (node)
	{
		next = node->next;
		free(node->str);
		free(node);
		node = next;
	}
	*head = NULL;
}
