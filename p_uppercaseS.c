#include "main.h"
/*task 5 */

/**
 * print_uppercaseS- print s in uppercase S
 * @v: va_
 * @f: pointer to flag
 * Return: number of chars
 */
int print_UppercaseS(va_list v, char f[],
	int params, int width, int precision, int size)
{
	int i = 0, os = 0;
	char *s = va_arg(v, char *);

	UNUSED(params);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (s == NULL)
		return (write(1, "(null)", 6));

	while (s[i] != '\0')
	{
		if (_isprintable(s[i]))
			f[i + os] = s[i];
		else
			os += _appendhexacode(s[i], f, i + os);

		i++;
	}

	f[i + os] = '\0';

	return (write(1, f, i + os));
}

