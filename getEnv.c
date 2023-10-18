#include "shell.h"

/**
 * get_environ - returns str array copy of our environ
 * @info: struct containing args
 * return: 0
 */
char **get_environ(info_t *info)
{
	if (!info->environ || info->env_ch)
	{
		info->environ = list_to_(info->env);
		info->env_ch = 0;
	}
	return (info->environ);
}

/**
 * _unsetenv - remove env var
 * @info: struct containing args
 * @var: str to va
 * return: 1 or 0
 */
int _unsetenv(info_t *info, char *var)
{
	list_t *node = info->env;
	size_t = 0;
	char *p;

	if (!node || !var)
		return (0);

	while (node)
	{
		p = starts_with(node->str, var);
		if (p && *p == '=')
		{
			info->env_ch = delete_node_at_ind(&(info->env), i);
			i = 0;
			node = info->rnv;
			continue;
		}
		node = node->next;
		i++;
	}
	return (info->env_ch);
}

/**
 * _setenv - init new var
 * @info: struct param
 * @var: variable str
 * @value: str value
 * return: 0
 */
int _setenv(info_t *info, char *var, char *value)
{
	char *buf = NULL;
	list_t *node;
	char *p;

	if (!var || !value)
		return (0);
	buf = malloc(_strlen(var) + _strlen(value) + 2);
	if (!buf)
		return(1);
	_strcpy(buf, var);
	_strcat(buf, "=");
	_strcat(buf, value);
	node = info->env;
	while (node)
	{
		p = starts_with(node->str, var);
		if (p && *p == '=')
		{
			free(node->str);
			node->str = buf;
			info->env_ch = 1;
			return (0);
		}
		node = node->next;
	}
	add_node_end(&(info->env), buf, 0);
	free(buf);
	info->env_ch = 1;
	return (0);

}
