#include "main.h"

/**Function's like putchar*/

/**
 * catchar - print a charcter to the standard output
 * @x: character to print
 * Return: 1 on success, -1 otherwise
 */

int catchar(char x)
{
	return (write(1, &x, 1));
}
