#include <stdarg.h>
#include <unistd.h>
#include "main.h"

/**
 * print_char - print a character
 * @arg: argument list
 * Return: length of the character
 */
int print_char(va_list arg)
{
	char c;
	int count;

	c = va_arg(arg, int);

	count = write(1, &c, 1);
	return (count);
}

/**
 * print_str - print a string
 * @arg: argument list
 * Return: length of the string
 */
int print_str(va_list arg)
{
	char *str;
	int count = 0, i;

	str = va_arg(arg, char *);
	if (str == NULL)
	{
		return (count);
	}

	i = 0;
	while (*(str + i))
	{
		write(1, &(*(str + i)), 1);
		i++;
		count++;
	}
	return (count);
}

/**
 * print_cent - print percentage
 * @arg: argument list
 * Return: length of the argument
 */
int print_cent(va_list arg)
{
	va_list percent;
	int count = 0;
	char c;

	va_copy(percent, arg);

	c = va_arg(percent, int);
	c = '%';

	count = write(1, &c, 1);
	va_end(percent);
	return (count);
}
