#include "main.h"
/*task 6 */
/**
 * print_address - print adress p
 * @v: va_list
 * @f: pointer to glag
 * @params: xxx
 * @width: xxx
 * @precision :xxx
 * @size: xxx
 * Return: number of chars
 */
int print_address(va_list v, char f[],
	int params, int width, int precision, int size)
{
	char ec = 0, pd = ' ';
	int ind = BUFF_SIZE - 2, length = 2, pd_start = 1;
	unsigned long num_address;
	char map_to[] = "0123456789abcdef";
	void *address = va_arg(v, void *);

	UNUSED(width);
	UNUSED(size);

	if (address == NULL)
		return (write(1, "(nil)", 5));

	f[BUFF_SIZE - 1] = '\0';
	UNUSED(precision);

	num_address = (unsigned long)address;

	while (num_address > 0)
	{
		f[ind--] = map_to[num_address % 16];
		num_address /= 16;
		length++;
	}

	if ((params & ZERO) && !(params & MINUS))
		pd = '0';
	if (params & PLUS)
		ec = '+', length++;
	else if (params & SPACE)
		ec = ' ', length++;

	ind++;

	return (writeadress(f, ind, length,
		width, params, pd, ec, pd_start));
}

