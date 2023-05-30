#include "main.h"
/* task2  b */

/**
 * print_binary - prints number in binary  b ( base 2)
 * @v: va_list
 * @f: pointer to flag struct
 * Return: number of chars
 */
int print_binary(va_list v, char f[],
	int params, int width, int precision, int size)
{
	unsigned int n, m, i, sum;
	unsigned int a[32];
	int count;

	UNUSED(f);
	UNUSED(params);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	n = va_arg(v, unsigned int);
	m = 2147483648; /* (2 ^ 31) */
	a[0] = n / m;
	for (i = 1; i < 32; i++)
	{
		m /= 2;
		a[i] = (n / m) % 2;
	}
	for (i = 0, sum = 0, count = 0; i < 32; i++)
	{
		sum += a[i];
		if (sum || i == 31)
		{
			char z = '0' + a[i];

			write(1, &z, 1);
			count++;
		}
	}
	return (count);
}

