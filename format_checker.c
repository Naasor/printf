#include "main.h"
/**
 * format_checker - checks for valid format
 * @format: possible valid format
 * @fn_list: array of possible functions
 * @fmt: array of all arguments
 * Return: total number of charcter printed
 */
int format_checker(const char *format, output_t fn_list[], va_list fmt)
{
	int i, y, val, output_chars = 0;

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			for (y = 0; fn_list[y].type != NULL; y++)
			{
				if (format[i + 1] == fn_list[y].type[0])
				{
					val = fn_list[y].fn(fmt);
					if (val == -1)
						return (-1);
					output_chars += val;
					break;
				}
			}
			if (fn_list[y].type == NULL && format[i + 1] != ' ')
			{
				if (format[i + 1] != '\0')
				{
					catchar(format[i]);
					catchar(format[i + 1]);
					output_chars = output_chars + 2;
				}
				else
					return (-1);
			}
			i = i + 1;
		}
		else
		{
			catchar(format[i]);
			output_chars++;
		}
	}
	return (output_chars);
}
