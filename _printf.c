#include "main.h"
/**
 * _printf - function that prints format to the stdout put
 * @format: arguments to be printed
 * Return: characters
 */
int _printf(const char *format, ...)
{
	int output_chars;

	output_t fn_list[] = {
		{"c", output_c},
		{"s", output_s},
		{"%", output_cent},
		{"d", output_di},
		{"i", output_di},
		{"b", output_b},
		{"o", output_o},
		{"u", output_u},
		/*{"S", output_S},*/
		/*{"p", output_p},*/
		{"x", output_x},
		{"X", output_X},
		{"r", output_r},
		{"R", output_R},
		{NULL, NULL}
	};

	va_list fmt;

	if (format == NULL)
		return (-1);

	va_start(fmt, format);

	output_chars = format_checker(format, fn_list, fmt);

	va_end(fmt);

	return (output_chars);
}
