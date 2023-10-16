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



#endif
