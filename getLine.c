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
