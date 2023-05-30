#include "main.h"

void printbuffer(char buffer[], int *bi);


/**
 * _printf - printf fonction and check
 * tasks 7 08  9 010 11 12
 * @format: format string
 * Return: carachters
 */
int _printf(const char *format, ...)
{
	int i, pd = 0, pdc = 0;
	int params, width, precision, size, bi = 0;
	va_list vl;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(vl, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[bi++] = format[i];
			if (bi == BUFF_SIZE)
				printbuffer(buffer, &bi);
			pdc++;
		}
		else
		{
			printbuffer(buffer, &bi);
			params = get_params(format, &i);
			width = get_width(format, &i, vl);
			precision = get_precision(format, &i, vl);
			size = get_size(format, &i);
			++i;
			pd = get_print(format, &i, vl, buffer,
				params, width, precision, size);
			if (pd == -1)
				return (-1);
			pdc += pd;
		}
	}

	printbuffer(buffer, &bi);

	va_end(vl);

	return (pdc);
}

/**
 * printbuffer - Prints the contents of the buffer
 * @buffer: Array of chars
 * @bi: param
 */
void printbuffer(char buffer[], int *bi)
{
	if (*bi > 0)
		write(1, &buffer[0], *bi);

	*bi = 0;
}


