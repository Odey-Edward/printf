#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stddef.h>
#include <unistd.h>
#include <limits.h>

int _printf(const char *format, ...);
int (*check_specifier(const char *c))(va_list arg);
int print_char(va_list arg);
int print_str(va_list arg);
int print_cent(va_list arg);
int print_dec(va_list arg);
int print_int(va_list arg);
int _putchar(char c);
int _abs(int n);

/**
 * struct argsList - structure for our format and the corresponding function
 * @ch: pointer to a character
 * @f: pointer to a function
 */
typedef struct argsList
{
	char *ch;
	int (*f)(va_list arg);
} args_t;

#endif
