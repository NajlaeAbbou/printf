#include "main.h"

/* task 3  u */

/**
 * print_unsignednumber - prints unsigned integer u
 * @v: va_list
 * @f: pointer of flag
 * @params: xxx
 * @width: xxx
 * @precision :xxx
 * @size: xxx
 * Return: number of chars
 */

int print_unsigned(va_list v, char f[],
	int params, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(v, unsigned long int);

	UNUSED(f);
	UNUSED(params);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	num = convertsizeunsgnd(num, size);

	if (num == 0)
		f[i--] = '0';

	f[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		f[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (writeunsgnd(i, f, params, width, precision, size));
}

/*task 3 o */

/**
 * print_octal - prints a number in octal o (base 8)
 * @v: va_list
 * @f: pointer  flag
 * @params: xxx
 * @width: xxx
 * @precision :xxx
 * @size: xxx
 * Return: number of chars
 */

int print_octal(va_list v, char f[],
	int params, int width, int precision, int size)
{

	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(v, unsigned long int);
	unsigned long int initnum = num;

	UNUSED(f);
	UNUSED(params);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	num = convertsizeunsgnd(num, size);

	if (num == 0)
		f[i--] = '0';

	f[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		f[i--] = (num % 8) + '0';
		num /= 8;
	}

	if (params & HASH && initnum != 0)
		f[i--] = '0';

	i++;

	return (writeunsgnd(i, f, params, width, precision, size));
}

/**
 * print_hexadecimal_lowercase- prints a number in hexadecimal x (base 16)
 * @v: va_list arguments
 * @f: pointer flag
 * @params: xxx
 * @width: xxx
 * @precision :xxx
 * @size: xxx
 * Return: number of chars
 */

int print_hexadecimal_lowercase(va_list v, char f[],
	int params, int width, int precision, int size)
{
	return (printhexa(v, "0123456789abcdef", f,
		params, 'x', width, precision, size));
}

/**
 * print_hexadecimal_uppercase - prints a number in hexadecimal X (base 16).
 * @v: va_list
 * @f: pointer flag
 * @params: xxx
 * @width: xxx
 * @precision :xxx
 * @size: xxx
 * Return: number of chars
 */
int print_hexadecimal_uppercase(va_list v, char f[],
	int params, int width, int precision, int size)
{
	return (printhexa(v, "0123456789ABCDEF", f,
		params, 'X', width, precision, size));
}

/**
 * printhexa - Prints a hexadecimal number in lower or upper
 * @v: Lista of arguments
 * @map_to: Array of values to map the number to
 * @f: f array to handle print
 * @params: xxx
 * @width: xxx
 * @precision :xxx
 * @size: xxx
 * @flag: nn
 * Return: Number of chars printed
 */
int printhexa(va_list v, char map_to[], char f[],
	int params, char flag, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(v, unsigned long int);
	unsigned long int initnum = num;

	UNUSED(f);
	UNUSED(params);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	num = convertsizeunsgnd(num, size);

	if (num == 0)
		f[i--] = '0';

	f[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		f[i--] = map_to[num % 16];
		num /= 16;
	}

	if (params & HASH && initnum != 0)
	{
		f[i--] = flag;
		f[i--] = '0';
	}

	i++;

	return (writeunsgnd(i, f, params, width, precision, size));
}


