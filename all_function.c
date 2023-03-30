#include <stdarg.h>
#include <unistd.h>
#include <limits.h>
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

	count = _putchar(c);
	return (count);
}

/**
 * print_str - print a string
 * @arg: argument list
 * Return: length of the string
 */
int print_str(va_list arg)
{
	char *str, *str2;
	int count = 0, i;

	str = va_arg(arg, char *);

	if (str == NULL)
	{
		va_list arg2;

		va_copy(arg2, arg);

		str2 = va_arg(arg2, char *);
		str2 = "(null)";

		for (i = 0; str2[i]; i++)
		{
			_putchar(str2[i]);
		}
		va_end(arg2);
		return (0);
	}

	i = 0;
	while (*(str + i))
	{
		count += _putchar(str[i]);
		i++;
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

	count += _putchar(c);
	va_end(percent);
	return (count);
}

/**
 * print_dec - print decimal
 * @arg: argument list
 * Return: length of argument
 */

int print_dec(va_list arg)
{
	int nums = va_arg(arg, int);
	int i = 0, count = 0;
	int numArr[10];

	if (nums != 0)
	{

		if (nums < 0)
		{
			count += _putchar('-');
		}
		if (nums == INT_MIN)
			nums = INT_MAX;
		nums = _abs(nums);
		while (nums != 0)
		{
			numArr[i] = nums % 10;
			nums = nums / 10;
			if (nums == 0)
				break;

			i++;
		}

		for (; i >= 0; i--)
		{
			count += _putchar('0' + numArr[i]);
		}
	}
	else
		count += _putchar('0');

	return (count);
}

/**
 * print_int - print integer
 * @arg: list of arguments
 * Return: length of arguments
 */

int print_int(va_list arg)
{
	int nums = va_arg(arg, int);
	int i, count = 0;
	int numArr[10];

	i = 0;

	if (nums != 0)
	{
		if (nums < 0)
		{
			count += _putchar('-');
		}
		if (nums == INT_MIN)
			nums = INT_MAX;
		nums = _abs(nums);

		if (nums < 0)
		{
			count += _putchar('-');
		}
		nums = _abs(nums);
		while (nums != 0)
		{
			numArr[i] = nums % 10;
			nums = nums / 10;
			if (nums == 0)
				break;

			i++;
		}
		for (; i >= 0; i--)
		{
			count += _putchar('0' + numArr[i]);
		}
	}
	else
		count += _putchar('0');

	return (count);
}
