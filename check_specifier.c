#include "main.h"

/**
 * check_specifier - return a pionter with the matching format
 * @c: format specifier
 * Return: pointer a pointer to a function
 */
int (*check_specifier(const char *c))(va_list args)
{
	int i;

	args_t func_cs[] = {
		{"c", print_char},
		{"s", print_str},
		{"%", print_cent},
		{"d", print_dec},
		{"i", print_int},
		{NULL, NULL}};

	i = 0;
	while (func_cs[i].ch)
	{
		if (*(func_cs[i].ch) == *c)
		{
			return (func_cs[i].f);
		}
		i++;
	}
	return (NULL);
}
