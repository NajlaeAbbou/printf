#include "main.h"

/**
 * print_char - fuction prit a char c
 * @v: va_list
 * @f: pointer struct flag
 * Return: number of chars to print
 */
int print_char(va_list v, char f[],
	int params, int width, int precision, int size)
{
	char c = va_arg(v, int);

	UNUSED(f);
	UNUSED(params);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	return (writechar(c, f, params, width, precision, size));
}
/* task 0 */

/**
 * print_string - a function prints all strings s
 * @v: va_list
 * @f: pointer to the struct flag
 * Return: number of chars to print
 */
int print_string(va_list v, char f[],
	int params, int width, int precision, int size)
{
	int length = 0, i;
	char *s = va_arg(v, char *);

	UNUSED(f);
	UNUSED(params);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	if (s == NULL)
	{
		s = "(null)";
		if (precision >= 6)
			s = "      ";
	}

	while (s[length] != '\0')
		length++;

	if (precision >= 0 && precision < length)
		length = precision;

	if (width > length)
	{
		if (params & MINUS)
		{
			write(1, &s[0], length);
			for (i = width - length; i > 0; i--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (i = width - length; i > 0; i--)
				write(1, " ", 1);
			write(1, &s[0], length);
			return (width);
		}
	}

	return (write(1, s, length));
}

/**
 * print_percent - prints a percent
 * @v: va_list
 * @f: pointer
 * Return: number of chars
 */

int print_percent(va_list v, char f[],
	int params, int width, int precision, int size)
{
	return (write(1, "%%", 1));
}

