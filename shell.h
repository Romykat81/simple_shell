#ifndef _SHELL_H_
#define _SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys.types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define FLUSH -1

#define CMD_NORM	0
#define CMD_OR		1
#define CMD_AND		2
#define CMD_CHAIN	3

#define CONVERT_LOWERCASE	1
#define CONVERT_UNSIGNED	2

#define USE_GETLINE 0
#define USE_STRTOK 0

#define HIST_FILE	"simple_shell_hist"
#define HIST_MAX	4096

extern char **environ;

/**
 * struct listst - sll
 * @num: number
 * @str: string
 * @next: ptr to next node
 */
typedef struct listst
{
	int num;
	char *str;
	struct listst *next;
} list_t;

/**
 * struct pass - function ptr struct for args
 * @arg: string of args
 * @argv: vector for string
 * @path: path for string
 * @argc: count args
 * @line_count: error counter
 * @err_num: error code for exit
 * @lc_flag: line of input to flag
 * @file_name: program file
 * @env: environment for ll
 * @environ: cpy of env
 * @history: history
 * @alias: alias 
 * @env_ch: if environ is changed
 * @stat: status of last exec cmd
 * @cmd_buf: addr to ptr to cmd_buf
 * @cmd_buf_type: cmd_type ||, &&, ;
 * @read_fd: the fd to read line input
 * @histcount: hist line no.
 */
typedef struct pass
{
	char **arg;
	char **argv;
	char *path;
	int argc;
	unsigned int line_count;
	int err_num;
	int lc_flag;
	char *file_name;
	lits_t *env;
	list_t *history;
	lits_t *alias;
	char **environ;
	int env_ch;
	int stat;

	char **cmd_buf;
	int cmd_buf_type;
	int read_fd;
	int histcount;
} info_t;

#define INFO_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
	0, 0, 0}



#endif
