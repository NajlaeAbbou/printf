#include "main.h"
/* taskn 13 */

/**
 * print_reverse - prints string in reverse r
 * @v: va_list
 * @f: pointer flag
 * @params: xxx
 * @width: xxx
 * @precision :xxx
 * @size: xxx
 * Return: length of string
 */

int print_reverse(va_list v, char f[],
	int params, int width, int precision, int size)
{
	char *s;
	int i, count = 0;

	UNUSED(f);
	UNUSED(params);
	UNUSED(width);
	UNUSED(size);

	s = va_arg(v, char *);

	if (s == NULL)
	{
		UNUSED(precision);

		s = ")Null(";
	}
	for (i = 0; s[i]; i++)
		;
	for (i = i - 1; i >= 0; i--)
	{
		char z = s[i];

		write(1, &z, 1);
		count++;
	}
	return (count);
}
