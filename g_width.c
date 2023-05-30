#include "main.h"

/**
 * get_width - Handle the field width for non-custom conversion specifiers.
 * @format: Formatted string in which to print the arguments.
 * @i: vl of arguments .
 * @vl: vl of arguments.
 * Return: width.
 */
int get_width(const char *format, int *i, va_list vl)
{
	int ci;
	int width = 0;

	for (ci = *i + 1; format[ci] != '\0'; ci++)
	{
		if (_isdigit(format[ci]))
		{
			width *= 10;
			width += format[ci] - '0';
		}
		else if (format[ci] == '*')
		{
			ci++;
			width = va_arg(vl, int);
			break;
		}
		else
			break;
	}
	*i = ci - 1;
	return (width);
}
