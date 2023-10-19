#include "shell.h"

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
 return (write(1, &c, 1));
}

/**
 * main - prints "Programming is like building a multilingual
 *	puzzle, followed by a new line.
 *
 * Return: Always 0.
 */
int main(void)
{
	puts("\"Programming is like building a multilingual puzzle");

	return (0);
}

/**
 * _strdup - copies a string into a new buffer
 * @str: string to copy
 * Return: pointer
 */
char *_strdup(char *str)
{
	char *p;
	unsigned int i, j;

	if (str == NULL)
		return (NULL);
	for (i = 0; str[i] != '\0'; i++)
	{
		;
	}
	i++;
	if (i < 1)
		return (NULL);
	p = malloc(i * sizeof(char));
	if (p == NULL)
	{
		free(p);
		return (NULL);
	}
	for (j = 0; j < i; j++)
		p[j] = str[j];
	p[j] = '\0';
	return (p);
}

/**
 * char *_strcpy - a function that copies the string pointed to by src
 * @dest: copy to
 * @src: copy from
 * Return: string
 */
char *_strcpy(char *dest, char *src)
{
	int l = 0;
	int x = 0;


	while (*(src + l) != '\0')
	{
		l++;
	}
	for ( ; x < l ; x++)
	{
		dest[x] = src[x];
	}
	dest[l] = '\0';
	return (dest);
}
