#include "main.h"
/* task 14 */
/**
 * print_rot13 - pprint s using rot13 R
 * @v: va_list
 * @f: pointer to flag
 * @params: xxx
 * @width: xxx
 * @precision :xxx
 * @size: xxx
 * Return: length of string
 */

int print_rot13(va_list v, char f[],
	int params, int width, int precision, int size)
{
	char x;
	char *s;
	unsigned int i, j;
	int count = 0;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	s = va_arg(v, char *);
	UNUSED(f);
	UNUSED(params);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (s == NULL)
		s = "(AHYY)";
	for (i = 0; s[i]; i++)
	{
		for (j = 0; in[j]; j++)
		{
			if (in[j] == s[i])
			{
				x = out[j];
				write(1, &x, 1);
				count++;
				break;
			}
		}
		if (!in[j])
		{
			x = s[i];
			write(1, &x, 1);
			count++;
		}
	}
	return (count);
}
