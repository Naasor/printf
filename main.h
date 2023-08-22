#ifndef MAIN_H
#define MAIN_H

/*standard library headers*/

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

/*Functions*/

/**
 * struct output - structure for printing out various types
 * @type: type to print
 * @fn: function to print
 */
typedef struct output
{
	char *type;
	int (*fn)(va_list);
} output_t;

int _printf(const char *format, ...);
int catchar(char x);
int format_checker(const char *format, output_t fn_list[], va_list fmt);
int output_num(va_list n);
int output_unsignednum(unsigned int);
char *string_rev(char *s);
void base_writer(char *str);
unsigned int len_base(unsigned int num, int base);
char *_memcpy(char *dest, char *src, unsigned int n);

int output_c(va_list);
int output_s(va_list);
int output_cent(va_list);
int output_di(va_list);
int output_di(va_list);
int output_b(va_list);
int output_o(va_list o);
int output_u(va_list);
int output_x(va_list x);
int output_X(va_list X);
int output_S(va_list);
/*int output_p(va_list p);*/


#endif
