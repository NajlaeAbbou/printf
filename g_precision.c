#include "main.h"

/**
 * get_precision - Handle the precision for non-custom conversion specifiers.
 * @format: string
 * @i: vl of arguments
 * @vl: vl of arguments.
 *
 * Return: Precision.
 */
int get_precision(const char *format, int *i, va_list vl)
{
	int ci = *i + 1;
	int precision = -1;

	if (format[ci] != '.')
		return (precision);

	precision = 0;

	for (ci += 1; format[ci] != '\0'; ci++)
	{
		if (_isdigit(format[ci]))
		{
			precision *= 10;
			precision += format[ci] - '0';
		}
		else if (format[ci] == '*')
		{
			ci++;
			precision = va_arg(vl, int);
			break;
		}
		else
			break;
	}

	*i = ci - 1;

	return (precision);
}
