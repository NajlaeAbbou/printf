#include "main.h"
/**
 * get_size - Handle the following length modifiers
 * for non-custom conversion specifiers:
 * @format: string
 * @i: List of arguments.
 *
 * Return: size.
 */
int get_size(const char *format, int *i)
{
	int curr_i = *i + 1;
	int size = 0;

	if (format[curr_i] == 'l')
		size = LONG;
	else if (format[curr_i] == 'h')
		size = SHORT;
	if (size == 0)
		*i = curr_i - 1;
	else
		*i = curr_i;
	return (size);
}
