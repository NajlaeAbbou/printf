#include "main.h"

/**
 * writechar - Prints a string
 * @c: char types.
 * @f: f array to handle print
 * @params: xxx
 * @width: xxx
 * @precision :xxx
 * @size: xxx
 * Return: Number of chars printed.
 */
int writechar(char c, char f[],
	int params, int width, int precision, int size)
{
	int i = 0;
	char padd = ' ';

	UNUSED(precision);
	UNUSED(size);
	UNUSED(f);
	UNUSED(params);
	UNUSED(width);

	if (params & ZERO)
		padd = '0';

	f[i++] = c;
	f[i] = '\0';

	if (width > 1)
	{
		f[BUFF_SIZE - 1] = '\0';
		for (i = 0; i < width - 1; i++)
			f[BUFF_SIZE - i - 2] = padd;

		if (params & MINUS)
			return (write(1, &f[0], 1) +
					write(1, &f[BUFF_SIZE - i - 1], width - 1));
		else
			return (write(1, &f[BUFF_SIZE - i - 1], width - 1) +
					write(1, &f[0], 1));
	}

	return (write(1, &f[0], 1));
}

/**
 * writenumber - Prints a string
 * @isnegative: Lista of arguments
 * @ind: char types.
 * @f: f array to handle print
 * @params: xxx
 * @width: xxx
 * @precision :xxx
 * @size: xxx
 * Return: Number of chars printed.
 */
int writenumber(int isnegative, int ind, char f[],
	int params, int width, int precision, int size)
{
	int length = BUFF_SIZE - ind - 1;
	char padd = ' ', ch = 0;

	UNUSED(size);

	if ((params & ZERO) && !(params & MINUS))
		padd = '0';
	if (isnegative)
		ch = '-';
	else if (params & PLUS)
		ch = '+';
	else if (params & SPACE)
		ch = ' ';

	return (writenum(ind, f, params, width, precision,
		length, padd, ch));
}

/**
 * writenum - Write a number using a bufffer
 * @ind: Index at which the number starts on the f
 * @f: f
 * @params: xxx
 * @width: xxx
 * @prec : xxx
 * @length: sss
 * @padd: cc
 * @extra_c: xxx
 * Return: Number of printed chars.
 */
int writenum(int ind, char f[],
	int params, int width, int prec,
	int length, char padd, char extra_c)
{
	int i, padd_start = 1;

	if (prec == 0 && ind == BUFF_SIZE - 2 && f[ind] == '0' && width == 0)
		return (0);
	if (prec == 0 && ind == BUFF_SIZE - 2 && f[ind] == '0')
		f[ind] = padd = ' ';
	if (prec > 0 && prec < length)
		padd = ' ';
	while (prec > length)
		f[--ind] = '0', length++;
	if (extra_c != 0)
		length++;
	if (width > length)
	{
		for (i = 1; i < width - length + 1; i++)
			f[i] = padd;
		f[i] = '\0';
		if (params & MINUS && padd == ' ')
		{
			if (extra_c)
				f[--ind] = extra_c;
			return (write(1, &f[ind], length) + write(1, &f[1], i - 1));
		}
		else if (!(params & MINUS) && padd == ' ')
		{
			if (extra_c)
				f[--ind] = extra_c;
			return (write(1, &f[1], i - 1) + write(1, &f[ind], length));
		}
		else if (!(params & MINUS) && padd == '0')
		{
			if (extra_c)
				f[--padd_start] = extra_c;
			return (write(1, &f[padd_start], i - padd_start) +
				write(1, &f[ind], length - (1 - padd_start)));
		}
	}
	if (extra_c)
		f[--ind] = extra_c;
	return (write(1, &f[ind], length));
}

/**
 * writeunsgnd - Writes an unsigned number
 * @ind: Index at which the number starts in the f
 * @f: Array of chars
 * @params: params specifiers
 * @width: xxx
 * @precision :xxx
 * @size: xxx
 * Return: Number chars.
 */
int writeunsgnd(int ind, char f[],
		int params, int width, int precision, int size)
{
	int length = BUFF_SIZE - ind - 1, i = 0;
	char padd = ' ';

	UNUSED(size);

	if (precision == 0 && ind == BUFF_SIZE - 2 && f[ind] == '0')
		return (0);

	if (precision > 0 && precision < length)
		padd = ' ';

	while (precision > length)
	{
		f[--ind] = '0';
		length++;
	}

	if ((params & ZERO) && !(params & MINUS))
		padd = '0';

	if (width > length)
	{
		for (i = 0; i < width - length; i++)
			f[i] = padd;

		f[i] = '\0';

		if (params & MINUS)
		{
			return (write(1, &f[ind], length) + write(1, &f[0], i));
		}
		else
		{
			return (write(1, &f[0], i) + write(1, &f[ind], length));
		}
	}

	return (write(1, &f[ind], length));
}

/**
 * writeadress - Write a memory address
 * @f: Arrays of chars
 * @ind: Index at which the number starts in the f
 * @params: xxx
 * @width: xxx
 * @length: cc
 * @padd: cc
 * @extra_c: ff
 * @padd_start:aa
 * Return: Number of written chars.
 */
int writeadress(char f[], int ind, int length,
	int width, int params, char padd, char extra_c, int padd_start)
{
	int i;

	if (width > length)
	{
		for (i = 3; i < width - length + 3; i++)
			f[i] = padd;
		f[i] = '\0';
		if (params & MINUS && padd == ' ')
		{
			f[--ind] = 'x';
			f[--ind] = '0';
			if (extra_c)
				f[--ind] = extra_c;
			return (write(1, &f[ind], length) + write(1, &f[3], i - 3));
		}
		else if (!(params & MINUS) && padd == ' ')
		{
			f[--ind] = 'x';
			f[--ind] = '0';
			if (extra_c)
				f[--ind] = extra_c;
			return (write(1, &f[3], i - 3) + write(1, &f[ind], length));
		}
		else if (!(params & MINUS) && padd == '0')
		{
			if (extra_c)
				f[--padd_start] = extra_c;
			f[1] = '0';
			f[2] = 'x';
			return (write(1, &f[padd_start], i - padd_start) +
				write(1, &f[ind], length - (1 - padd_start) - 2));
		}
	}
	f[--ind] = 'x';
	f[--ind] = '0';
	if (extra_c)
		f[--ind] = extra_c;
	return (write(1, &f[ind], BUFF_SIZE - ind - 1));
}

