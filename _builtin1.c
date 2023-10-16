#include "shell.h"

/**
 * _myhist - hist list
 * @info: struct param
 *
 * return: 0
 */
int _myhist(info_t *info)
{
	print_list(info->history);
	return (0);
}

/**
 * unset_alias - set alias to str
 * @info: struct param
 * @str: str alias
 *
 * return: 0 or 1
 */
int unset_alias(info_t *info, char *str)
{
	char *i, j;
	int r;

	i = _strchr(str, '=');
	if (!i)
		return (1);
	j = *i;
	*i = 0;
	r = delete_node_at_index(&(info->alias),
			get_node_index(info->alias, note_starts_with(info->alias, str, -1)));
	*i = j;
	return (r);
}

/**
 * set_alias - set alias to str
 * @info: struct param
 * @str: str alias
 *
 * return: 0 or 1
 */
int set_alias(info_t *info, char *str)
{
	char *i;

	i = _strchr(str, '=');
	if (!i)
		return (1);
	if (!*++i)
		return (unset_alias(info, str));

	unset_alias(info, str);
	return (add_node_end(&(info->alias), str, 0) == NULL);
}

/**
 * print_alias - prints alias str
 * @node: alias node
 *
 * return: 0 or 1
 */
int print_alias(list_t *node)
{
	char *i = NULL, *j = NULL;

	if (node)
	{
		i = _strchr(node->str, '=');
		for (j = node->str; j <= i; j++)
			_putchar(*j);
		_putchar('\'');
		_puts(i + 1);
		_puts("'\n");
		return (0);
	}
	return (1)
}

/**
 * _myalias - mimics alias - man alias
 * @info: struct param
 *
 * return: 0
 */
int _myalias(info_t *info)
{
	int i = 0;
	char *j = NULL;
	list_t *node = NULL;

	if (info->argc == 1)
	{
		node = info->alias;
		while (node)
		{
			print_alias(node);
			node = node->next;
		}
		return (0);
	}
	for (i = 1; info->argv[i]; i++)
	{
		j = _strchr(info->argv[i], '=');
		if (j)
			set_alias(info, info->argv[i]);
		else
			print_alias(node_starts_with(info->alias, info->argv[i], '='));
	}

	return (0);
}
