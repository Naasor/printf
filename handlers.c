#include "main.h"

/**
 * string_rev - reverses a string in place
 * @s: string to reverse
 * Return: A pointer to a reversed character
 */
char *string_rev(char *s)
{
	int len;
	int start;
	char tmp;
	char *dest;

	for (len = 0; s[len] != '\0'; len++)
	{}

	dest = malloc(sizeof(char) * len + 1);
	if (dest == NULL)
		return (NULL);

	_memcpy(dest, s, len);
	for (start = 0; start < len; start++, len--)
	{
		tmp = dest[len - 1];
		dest[len - 1] = dest[start];
		dest[start] = tmp;
	}
	return (dest);
}

/**
 * base_writer - sends characters to be written on standard output
 * @str: String to parse
 */
void base_writer(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
		catchar(str[i]);
}

/**
 * len_base - Calculates the length for an octal number
 * @num: The number for which the length is being calculated
 * @base: Base to be calculated by
 * Return: An integer of the length of a number
 */
unsigned int len_base(unsigned int num, int base)
{
	unsigned int i;

	for (i = 0; num > 0; i++)
	{
		num = num / base;
	}
	return (i);
}

/**
 * _memcpy - copy memory area
 * @dest: Destination for copying
 * @src: Source to copy from
 * @n: The number of bytes to copy
 * Return: The _memcpy() function returns a pointer to dest.
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}
