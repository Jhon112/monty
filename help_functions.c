#include "monty.h"

/**
 * print_error - prints all the different errors according to its type
 * @error_type: pointer to string indicating type
 *
 * Return:  void - exit with EXIT_FAILURE
 */
void print_error(char  *error_type, ...)
{
	va_list replacers;

	va_start(replacers, error_type);
	if (_strcmp(error_type, "usage") == 0)
	{
		fprintf(stderr, "USAGE: monty file");
		exit(EXIT_FAILURE);
	}
	if (_strcmp(error_type, "open") == 0)
	{
		fprintf(stderr, va_arg(replacers, char *));
		exit(EXIT_FAILURE);
	}
}

/**
 * _strcmp - compare two strings
 * @s1: first string
 * @s2: second string
 *
 * Return: negative numb if s1 major than s2
 * positive numb if s1 major s2
 * 0 if same
 */
int _strcmp(char *s1, char *s2)
{
	int i, a;

	for (i = 0; *(s1 + i) != 0; i++)
	{
	}

	for (a = 0; a < i; a++)
	{
		if (s1[a] != s2[a])
			return (s1[a] - s2[a]);
	}
	return (0);
}
