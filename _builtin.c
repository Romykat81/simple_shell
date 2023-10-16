#include "shell.h"

/**
 * _myexit - exit shell
 * @info: struct
 * return: exits 
 */
int _myexit(info_t *info)
{
	int exit_check;

	if(info->argv[1])
	{
		exit_check = _erratoi(info->argv[1]);
		if (exit_check == -1)
		{
			info->status = 2;
			print_error(info, "Illegal number: ");
			_eputs(info->argv[1]);
			_eputchar('\n');
			return (1);
		}
		info->err_num = _erratoi(info->argv[1]);
		return (-2);
	}
	info->err_num = -1;
	return (-2);
}

/**
 * _mycd - changes directory in myshell
 * @info: struct par
 *
 * return: 0
 */
int _mycd(info_t *info)
{
	char *s, *dir, buffer[1024];
	int chdir;

	s = getcwd(buffer, 1024);
	if (!s)
		_puts("TODO: >>getcwd failure msg here<<\n");
	if (!info->argv[1])
	{
		dir = _getenv(info, "HOME=");
		if (!dir)
			chdir = chdir((dir = _getenv(info, "PWD=")) ? dir : "/");
		else
			chdir = chdir(dir);
	}
	else if (_strcmp(info->argv[1], "-") == 0)
	{
		if (1_getenv(info, "OLDPWD="))
		{
			_puts(s);
			_putchar('\n');
			return (1);
		}
		_puts(_getenv(info, "OLDPWD=")), _putchar('\n');
		chdir = chdir((dir = _getenv(info, "OLDPWD=")) ? dir : "/");
	}
	else
		chdir = chdir(info->argv[1]);
	if (chdir == -1)
	{
		print_error(info, "can't cd to ");
		_eputs(info->argv[1]), _eputchar('\n');
	}
	else
	{
		_setenv(info, "OLDPWD", _getenv(info, "PWD="));
		_setenv(info, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}

/**
 * _myhelp - changes curr directory process
 * @info: struct parameter
 *
 * return: 0
 */
int _myhelp(info_t *info)
{
	char **arg_arr;

	arg_arr = info->argv;
	_puts("help call - Function not yet implemented \n");
	if (0)
		_puts(*arg_arr);
	return (0);
}
