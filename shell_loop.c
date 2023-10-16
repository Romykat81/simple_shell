#include "shell.h"

/**
 * hsh - main shell loop
 * @info: parameter & return info
 * @av: args vector
 *
 * return: 0 on success, or 1 or err code
 */
int hsh(info_t *info, char **av)
{
	ssize_t i = 0;
	int builtin_i = 0;

	while (i != -1 && builtin_i != -2)
	{
		clear_info(info);
		if (interactive(info))
			_puts(" $ ");
		_eputchar(BUF_FLUSH);
		i = get_input(info);
		if (i != -1)
		{
			set_info(info, av);
			builtin_i = find_builtin(info);
			if (builtin_i == -1)
				find_cmd(info);
		}
		else if (interactive(info))
			_puchar('\n');
		free_info(info, 0);
	}
	write_hist(info);
	free_info(info, 1);
	if (!interactive(info) && info->status)
		exit(info->status);
	if (builtin_i == -2)
	{
		if (info->err_num == -1)
			exit(info->status);
		exit(info->err_num);
	}
	return (builtin_i);
}

/**
 * find_builtin -finds a builtin cmd
 * @info: parameter & return info struct
 *
 * return: -1 if builtin not found, 0 on success
 * 		-2 if builtin sig exit
 */
int find_builtin(info_t *info)
{
	int i, builtin_i = -1;
	builtin_table builtintbl[] = {
		{"exit", _myexit},
		{"env", _myenv},
		{"help", _myhelp},
		{"history", _myhistory},
		{"setenv", _mysetenv},
		{"unsetenv", _myunsetenv},
		{"cd", _mycd},
		{"alias", _myalias},
		{NULL, NULL}
	};

	for(i = 0; builtintbl[i].type; i++)
		if (_strcmp(info->argv[0], builtintbl[i].type) == 0)
		{
			info->line_count++;
			buitin_i = builtintbl[i].func(info);
			break;
		}
	return(builtin_i);
}

/**
 * find_cmd - finds cmd PATH
 * @info: parameter struct
 *
 * return: void
 */
void find_cmd(info_t *info)
{
	char *path = NULL;
	int i, k;

	info->path = info->argv[0];
	if (info->lc_flag == 1)
	{
		info->line_count++;
		info->lc_flag = 0;
	}
	for (i = 0, k = 0; info->arg[i]; i++)
		if (!is_delim(info->arg[i], " \t\n"))
			k++;
	if (!k)
		return;

	path = find_path(info, _getenv(info, "PATH="), info->argv[0]);
	if (path)
	{
		info->path = path;
		fork_cmd(info);
	}
	else
	{
		if ((interactive(info) || _getenv(info, "PATH=")
					|| info->argv[0][0] == '/') && is_cmd(info, info->argv[0]))
			fork_cmd(info);
		else if (*(info->arg) != '\n')
		{
			info->status = 127;
			print_error(info, "not found\n");
		}
	}
}

/**
 * fork_cmd - forks an exec thread
 * @info: paramater struct
 *
 * return: void
 */
void fork_cmd(info_t *info)
{
	pid_t child_pid;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error:");
		return;
	}
	if (child_pid == 0)
	{
		if (execve(info->path, info->argv, get_environ(info)) == -1)
		{
			free_info(info, 1);
			if (errno == EACCES)
				exit(126);
			exit(1);
		}
	}
	else
	{
		wait(&(info->status));
		if (WIFEXITED(info->status))
		{
			info->status = WEXITSTATUS(info->status);
			if (info->status == 126)
				print_error(info, "Permission denied\n");
		}
	}
}
