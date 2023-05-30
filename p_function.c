#include "main.h"

/**
 * _isprintable - Evaluates if a char is printable
 * @c: Char to be evaluated.
 * Return: 0 or 1
 */
int _isprintable(char c)
{
	if (c >= 32 && c < 127)
		return (1);

	return (0);
}

/**
 * _appendhexacode - Append ascci in hexadecimal code to buffer
 * @buffer: Array of chars.
 * @i: Index
 * @ascii_code: xxx
 * Return:  3
 */
int _appendhexacode(char ascii_code, char buffer[], int i)
{
	char map_to[] = "0123456789ABCDEF";

	if (ascii_code < 0)
		ascii_code *= -1;

	buffer[i++] = '\\';
	buffer[i++] = 'x';

	buffer[i++] = map_to[ascii_code / 16];
	buffer[i] = map_to[ascii_code % 16];

	return (3);
}

/**
 * _isdigit - Verifies if a char is a digit
 * @c: Char to be evaluated
 * Return: 1 or 0
 */
int _isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);

	return (0);
}

/**
 * convertsizenumber - Casts a number to the specified size.
 * @num: Number.
 * @size: size.
 *
 * Return: num
 */
long int convertsizenumber(long int num, int size)
{
	if (size == LONG)
		return (num);
	else if (size == SHORT)
		return ((short)num);

	return ((int)num);
}

/**
 * convertsizeunsgnd - Casts a number to the specified size
 * @num: Number
 * @size: size
 * Return: num
 */
long int convertsizeunsgnd(unsigned long int num, int size)
{
	if (size == LONG)
		return (num);
	else if (size == SHORT)
		return ((unsigned short)num);

	return ((unsigned int)num);
}
