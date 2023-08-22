#include "main.h"

/**
 * output_c - Print character
 * @c: list of arguments
 * Return: a single charcter
 */
int output_c(va_list c)
{
	catchar(va_arg(c, int));
	return (1);
}

/**
 * output_s - print string
 * @s: list of arguments
 * Return: string
 */
int output_s(va_list s)
{
	int i;
	char *str;

	str = va_arg(s, char *);
	if (str == NULL)
		str = "(null)";
	for (i = 0; str[i] != '\0'; i++)
		catchar(str[i]);
	return (i);
}

/**
 * output_cent - function that print percent symbol
 * @cent: list of arguments
 * Return: character
 */
int output_cent(__attribute__((unused))va_list cent)
{
	catchar('%');
	return (1);
}
