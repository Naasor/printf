#include "main.h"

/**
 * hex_checker - function that checks valid hex function call
 * @num: to convert to hex
 * @x: determins the type of Hex
 * Return: Ascii value hex
 */
int hex_checker(int num, char x)
{
	char *hex = "abcdef";
	char *heX = "ABCDEF";

	num = num - 10;

	if (x == 'x')
		return (hex[num]);
	else
		return (heX[num]);

	return (0);
}

/**
 * output_o - Prints signed octal base
 * @o: arguments
 * Return: octal numbers
 */
int output_o(va_list o)
{
	unsigned int num;
	int len;
	char *oct_rep;
	char *rev_str;

	num = va_arg(o, unsigned int);

	if (num == 0)
		return (catchar('0'));
	if (num < 1)
		return (-1);

	len = len_base(num, 8);

	oct_rep = malloc(sizeof(char) * len + 1);

	if (oct_rep == NULL)
		return (-1);
	for (len = 0; num > 0; len++)
	{
		oct_rep[len] = (num % 8) + 48;
		num = num / 8;
	}

	oct_rep[len] = '\0';
	rev_str = string_rev(oct_rep);
	if (rev_str == NULL)
		return (-1);
	base_writer(rev_str);
	free(oct_rep);
	free(rev_str);
	return (len);
}

/**
 * output_x - prints decimal numbers in base 16 lowercases
 * @x: arguments
 * Return: lowercases base 16
 */
int output_x(va_list x)
{
	unsigned int num;
	int len;
	int tem;
	char *x_rep;
	char *rev_hex;

	num = va_arg(x, unsigned int);

	if (num == 0)
		return (catchar('0'));
	if (num < 1)
		return (-1);

	len = len_base(num, 16);
	x_rep = malloc(sizeof(char) * len + 1);

	if (x_rep == NULL)
		return (-1);
	for (len = 0; num > 0; len++)
	{
		tem = num % 16;
		if (tem > 9)
		{
			tem = hex_checker(tem, 'x');
			x_rep[len] = tem;
		}
		else
			x_rep[len] = tem + 48;
		num = num / 16;
	}
	x_rep[len] = '\0';
	rev_hex = string_rev(x_rep);
	if (x_rep == NULL)
		return (-1);
	base_writer(rev_hex);
	free(x_rep);
	free(rev_hex);
	return (len);
}

/**
 * output_X - prints decimal numbers in base 16 uppercases
 * @X: arguments
 * Return: uppercases base 16
 */
int output_X(va_list X)
{
	unsigned int num;
	int len;
	int tem;
	char *X_rep;
	char *rev_heX;

	num = va_arg(X, unsigned int);

	if (num == 0)
		return (catchar('0'));
	if (num < 1)
		return (-1);

	len = len_base(num, 16);
	X_rep = malloc(sizeof(char) * len + 1);

	if (X_rep == NULL)
		return (-1);
	for (len = 0; num > 0; len++)
	{
		tem = num % 16;
		if (tem > 9)
		{
			tem = hex_checker(tem, 'X');
			X_rep[len] = tem;
		}
		else
			X_rep[len] = tem + 48;
		num = num / 16;
	}
	X_rep[len] = '\0';
	rev_heX = string_rev(X_rep);
	if (X_rep == NULL)
		return (-1);
	base_writer(rev_heX);
	free(X_rep);
	free(rev_heX);
	return (len);
}
