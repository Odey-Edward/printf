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
	int count = 0, i, value = 0;

	str = va_arg(arg, char *);

	if (str == NULL)
	{
		va_list arg2;

		va_copy(arg2, arg);

		str2 = va_arg(arg2, char *);
		str2 = "(null)";

		for (i = 0; str2[i]; i++)
		{
			value = _putchar(str2[i]);
			count += value;
		}
		va_end(arg2);
		return (count);
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
 * @args: argument list
 * Return: length of argument
 */
int print_dec(va_list args)
{
	int i = 0;
	int count = 0;
	long int numb;
	int my_arr[10];
	char x[1];

	/*Fetch integer from variadic parameters*/
	numb = va_arg(args, int);
	if (numb < 0)
	{
		numb = -((long int)(numb));
		count = _putchar('-');
	}
	if (numb > 0)
	{
		/*Break the numbers apart and assign them to array*/
		while (numb != 0)
		{
			my_arr[i] = (numb % 10);
			numb = numb / 10;
			if (numb == 0)
			{
				break;
			}
				i++;
		}
		/*Write the contents of the array to stdout*/
		for ((void)i; i >= 0; i--)
		{
			x[0] = ('0' + my_arr[i]); /*Convert int to char*/
			count += _putchar(x[0]);
		}

		return (count);
	}
	if (numb == 0)
	{
		count = _putchar(numb + '0');
	}
		return (count);
}

/**
 * print_int - print integer
 * @arg: list of arguments
 * Return: length of arguments
 */
int print_int(va_list arg)
{
	int i = 0;
	int count = 0;
	long int numb;
	int my_arr[10];
	char x[1];

	/*Fetch integer from variadic parameters*/
	numb = va_arg(arg, int);
	if (numb < 0)
	{
		numb = -((long int)(numb));
		count = _putchar('-');
	}
	if (numb > 0)
	{
		/*Break the numbers apart and assign them to array*/
		while (numb != 0)
		{
			my_arr[i] = (numb % 10);
			numb = numb / 10;
			if (numb == 0)
			{
				break;
			}
				i++;
		}
		/*Write the contents of the array to stdout*/
		for ((void)i; i >= 0; i--)
		{
			x[0] = ('0' + my_arr[i]); /*Convert int to char*/
			count += _putchar(x[0]);
		}

		return (count);
	}
	if (numb == 0)
	{
		count = _putchar(numb + '0');
	}
		return (count);
}
