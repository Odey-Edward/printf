#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stddef.h>
#include <unistd.h>

int _printf(const char *format, ...);
int (*check_specifier(const char *c))(va_list arg);
int print_char(va_list arg);
int print_str(va_list arg);
int print_cent(va_list arg);

/**
* struct argList - structure for our format and the corresponding function
* @ch: pointer to a character
* @f: pointer to a function
*/
typedef struct argsList
{
	char *ch;
	int (*f)(va_list arg);
} args_t;

#endif
