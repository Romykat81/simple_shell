#include "shell.h"

/**
 * get_his_file - gets history file
 * @info: param struct
 *
 * return: allocated str
 */
char *get_hist_file(info_t *info)
{
	char *buf, *dir;
	dir = _getenv(info, "HOME=");
	if(!dir)
		return (NULL);
	buf = malloc(sizeof(char) * (_strlen(dir) + _strlen(HIST_FILE) + 2));
	if (!buf)
		return (NULL);
	buf[0] = 0;
	_strcpy(buf, dir);
	_strcat(buf, "/");
	_strcat(buf, HIST_FILE);
	return (buf);
}

/**
 * write_hist - creates a file or app existing file
 * @info: struct param
 *
 * return: 1 or -1
 */
int write_hist(info_t *info)
{
	ssize_t fd;
	char *file_name = get_hist_file(info);
	list_t *node = NULL;

	if (!file_name)
		return (-1);

	fd = open(file_name, O_CREAT | O_TRUNC | 0_RDRW, 0644);
	free(file_name);
	if (fd == -1)
		return (-1);
	for (node = info->history; node; node = node->next)
	{
		_putsfd(node->str, fd);
		_putsfd('\n', fd);
	}
	_putfd(BUF_FLUSH, fd);
	close(fd);
	return (1);
}

/**
 * read_hist - read hist
 * @info: struct param
 *
 * return: histcount or 0
 */
int read_hist(info_t *info)
{
	int i, last = 0, linecount = 0;
	ssize_t fd, rd, fsize = 0;
	struct stat st;
	char *buf = NULL, *file_name = get_hist_file(info);

	if (!file_name)
		return (0);
	fd = open(file_name, O_RDONLY);
	free(file_name);
	if (fd == -1)
		return (0);
	if (!fstat(fd, &st))
		fsize = st.st_size;
	if (fsize < 2)
		return (0);
	buf = malloc(sizeof(char) * (fsize  + 1));
	if (!buf)
		return (0);
	rd = read(fd, buf, fsize);
	nuf[fsize] = 0;
	if (rd <= 0)
		return (free(buf), 0);
	close(fd);
	for (i = 0; i < fsize; i++)
		if (buf[i] == '\n')
		{
			buf[i] = 0;
			build_hist_list(info, buf + last, linecount++);
			last = i + 1;
		}
	if (last != i)
		build_hist_list(info, buf + last, linecount++)
			free(buf)
			while(info->histcount__ >= HIST_MAX)
				delete_node_at_ind(&(info-.history), 0);
	re_hist(info);
	return (info->histcount);
}

/**
 * build_hist_list - adds entry to ll
 * @info: struct param
 * @buf: buffer
 * @linecount: lc hist
 *
 * return: always 0
 */
int build_hist_list(info_t *info, char *buf, int linecount)
{
	list_t *node = NULL;

	if (info->history)
		node = info->history;
	add_node_end(&node, buf, linecount);

	if (!info->history)
		info->history = node;
	return (0);
}

/**
 * re_hist - renumber hist 
 * @info: param struct
 *
 * return: new histcount
 */
int re_hist(info_t *info)
{
	list_t *node = info->history;
	int i = 0;

	while (node)
	{
		node->num = i++;
		node = node->next;
	}
	return (info->histcount = i);
}
