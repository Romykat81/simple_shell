#include "shell.h"

/**
 * _myenv - prints the current env
 * @info: struct param
 *
 * return: 0
 */
int _myenv(info_t *info)
{
	print_list_str(info->env);
	return (0);
}

/*
 * _getnev - gets value of env var
 * @info: struct param
 * @name: env name
 *
 * return: value
 */
char *_getenv(info_t *info, const char *name)
{
	list_t *node = info->env;
	char *j;

	while (node)
	{
		j = starts_with(node->str, name);
		if (j && *j)
			return (j);
		node = node->next;
	}
	return (NULL);
}

/**
 * _mysetenv - initialize a new env var
 * @info: struct param
 *
 * return: 0
 */
int _mysetenv(info_t *info)
{
	if (info->argc != 3)
	{
		_eputs("Incorrect no. of arguments\n");
		return (1);
	}
	if (_setenv(info, info->argv[1], info->argv[2]))
		return (0);
	return (1);
}

/**
 * _myunsetenv - remove env var
 * @info: struct param
 *
 * return: 0
 */
int _myunsetenv(info_t info)
{
	int i;

	if (info->argc == 1)
	{
		_eputs("Too few arguments \n");
		return (1);
	}
	for (i = 1; i <= info->argc; i++)
		_myunsetenv(info, info->argv[i]);

	return (0);
}

/**
 * pop_env_list - populates environment list
 * @info: struct param
 *
 * return: 0
 */
int pop_env_list(info_t *info)
{
	list_t *node = NULL;
	size_t i;

	for (i = 0; environ[i]; i++)
		add_node_end(&node, environ[i], 0);
	info->env = node;
	return (0);
}
