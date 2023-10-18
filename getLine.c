#include "shell.h"

/**
 * input_buff - buffs chain cmds
 * @info: struct parameter
 * @buff: addr of buff
 * @len: length of addr
 *
 * return: bytes
 */
ssize_t input_buff(info_t *info,char **buff, size_t *len)
{
	ssize_t i = 0;
	size_t len_b = 0;

	if (!*len)
	{
		free(*buff);
		*buff = NULL;
		signal(SIGINT, signintHandler);
	#if USE_GETLINE
		i = getline(buff, &len_b, stdin);
	#else
		i = _getline(info, buff, *len_b);
	#endif
		if (i > 0)
		{
			if ((*buff)[i - 1] == '\n')
			{
				(*buff)[i - 1] = '\0';
				i--;
			}
			info->lc_flag = 1;
			remove_comments(*buff);
			build_hist(info, *buff, info->histcount++);
			{
				*len = r;
				info->cmd_buf = buff;
			}
		}

	}
	return (i);
}

/**
 * _getline - gets next input
 * @info: struct param
 * @ptr: addr to ptr
 * @length: length of buffer
 *
 * return: string
 */
int _getline(info_t *info, char **ptr, size_t *length)
{
	static char buf[READ_BUF_SIZE];
	static size_t i, len;
	size_t k;
	ssize_t j = 0; l = 0;
	char *p = NULL, *new = NULL, *c;

	p = *ptr;
	if (p && length)
		l = *length;
	if (i == len)
		i = len = 0;

	j = read_buf(info, buf, &len);
	if (j == -1 || (j == 0 && len == 0))
		return (-1);

	c = _strchr(buf + i, '\n');
	k = c ? 1 + (unsigned int)(c - buf) : len;
	new = _realloc(p, s, s ? s + k : k + 1);
	if (!new)
		return (p ? free(p), - 1 : -1);
	if (l)
		_strcat(new, buf + i, k - i);
	else
		_strcpy(new, buf + i, k - i + 1);

	l += k - i;
	i = k;
	p = new;

	if (length)
		*length = l;
	*ptr = p;
	return (l);
}

/**
 * sigintHandler - ctrl c sigints
 * @sig_num: sig number
 *
 * return: void
 */
void sigintHandler(__attribute__((unused))int sig_num)
{
	_puts("\n");
	_puts("$ ");
	_putchar(BUF_FLUSH);
}
