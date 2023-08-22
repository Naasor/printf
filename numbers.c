#include "main.h"

/**
 * output_num - print numbers
 * @n: argument
 * Return: number to be printed
 */
int output_num(va_list n)
{
	int x, set, len;
	unsigned int num;

	x = va_arg(n, int);
	set = 1;
	len = 0;

	if (x < 0)
	{
		len += catchar('-');
		num = x * -1;
	}
	else
		num = x;
	for (; num / set > 9; )
		set *= 10;
	for (; set != 0;)
	{
		len += catchar('0' + num / set);
		num %= set;
		set /= 10;
	}
	return (len);
}

/**
 * output_unsignednum - print unsigned number
 * @n: number to be printed
 * Return: number
 */
int output_unsignednum(unsigned int n)
{
	int set, len;
	unsigned int num;

	set = 1;
	len = 0;
	num = n;

	for (; num / set > 9; )
		set *= 10;
	for (; set != 0; )
	{
		len += catchar('0' + num / set);
		num %= set;
		set /= 10;
	}
	return (len);
}
