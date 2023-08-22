#include "main.h"

/**
 * output_di - print signed decimal integers
 * @di: list of arguments to be printed
 * Return: number of caracters to be printed
 */
int output_di(va_list di)
{
	int len;

	len = output_num(di);

	return (len);
}

/**
 * output_u - print unsigned decimal integer
 * @u: arguements
 * Return: number
 */
int output_u(va_list u)
{
	unsigned int n;

	n = va_arg(u, unsigned int);

	if (n == 0)
		return (output_unsignednum(n));

	if (n < 1)
		return (-1);

	return (output_unsignednum(n));
}

/**
 * output_b - a function that converts from base 10 to to binary
 * @b: arguments to function
 * Return: binary number
 */
int output_b(va_list b)
{
	unsigned int num;
	int i, len;
	char *str;
	char *rev_str;

	num = va_arg(b, unsigned int);

	if (num == 0)
		return (catchar('0'));
	if (num < 1)
		return (-1);
	len = len_base(num, 2);
	str = malloc(sizeof(char) * len + 1);
	if (str == NULL)
		return (-1);

	for (i = 0; num > 0; i++)
	{
		if (num % 2 == 0)
			str[1] = '0';
		else
			str[i] = '1';
		num = num / 2;
	}
	str[i] = '\0';
	rev_str = string_rev(str);
	if (rev_str == NULL)
		return (-1);
	base_writer(rev_str);
	free(str);
	free(rev_str);
	return (len);
}
