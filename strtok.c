#include "main.h"

/**
 * _strtok - tokenizes a null-terminated string
 * @str: the string to be tokenized
 * @delim: the delimiter
 * Return: pointer to the str
 */
char *_strtok(char *str, const char *delim)
{
	static __thread char *next = NULL;
	char *token;


	if (str == NULL)
		str = next;

	/* removing leading delimiters */
	while (*str != '\0' && strchr(delim, *str) != NULL)
		str++;

	if (*str == '\0')
		return (NULL);

	/* finds the end of the string */
	token = str;
	while (*str != '\0' && strchr(delim, *str) == NULL)
		str++;

	/* if a token is found, null terminate it */
	if (*str != '\0')
	{
		*str = '\0';
		next = str + 1; /* move to the next token */
	} else
		next = NULL;
	return (token);
}
