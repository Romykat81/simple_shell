 #include "shell.h"

/**
 * _erratoi - conv str to int 
 * @s: str
 * return: 0
 */
int _erratoi(char *s)
{
	int i = 0;
	unsigned long int res = 0;

	if (*s == '+')
		s++;
	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			res *= 10;
			res += (s[i] - '0');
			of (res > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (res);
}

/**
 * print_error - prints an err msg
 * @info: struct param
 * @stre: str error 
 *
 * return: 0
 */
void print_error(info_t *info, char *stre)
{
	_eputs(info->file_name);
	_eputs(": ");
	d_prints(info->line_count, STDERR_FILENO);
	_eputs(": ");
	_eputs(info->argv[0]);
	_eputs(": ");
	_eputs(stre);
}



