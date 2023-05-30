#include "main.h"
/* task 1 i and d */

/**
 * print_integer - prints integer i and d
 * @v: va_list from _printf
 * @f: pointer to the struct flag
 * Return: number of chararachers
 */

int print_int(va_list v, char f[],
	int params, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	int isnegative = 0;
	long int n = va_arg(v, long int);
	unsigned long int num;

	n = convertsizenumber(n, size);

	if (n == 0)
		f[i--] = '0';

	f[BUFF_SIZE - 1] = '\0';
	num = (unsigned long int)n;

	if (n < 0)
	{
		num = (unsigned long int)((-1) * n);
		isnegative = 1;
	}

	while (num > 0)
	{
		f[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (writenumber(isnegative, i, f, params, width, precision, size));
}

