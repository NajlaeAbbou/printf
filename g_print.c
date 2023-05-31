#include "main.h"
/**
 * get_print - select the right _printf function
 * @handlerPrint: character specifier
 * @ind: bb
 * @list: ff
 * @buffer: hh
 * @flags: ff
 * @width: ff
 * @precision: bb
 * @size: vf
 * Return: 1 or 2;
 */
int get_print(const char *handlerPrint, int *ind, va_list list, char buffer[],
	int flags, int width, int precision, int size)
{
	int i, len = 0, pc = -1;
	hp hp_types[] = {
		{'c', print_char}, {'s', print_string},
		{'%', print_percent}, {'i', print_int},
		{'d', print_int}, {'b', print_binary}, {'u', print_unsigned},
		{'o', print_octal}, {'x', print_hexadecimal_lowercase},
		{'X', print_hexadecimal_uppercase}, {'p', print_address},
		{'S', print_UppercaseS}, {'r', print_reverse}, {'R', print_rot13},
		{'\0', NULL}
	};
	for (i = 0; hp_types[i].handlerPrint != '\0'; i++)
		if (handlerPrint[*ind] == hp_types[i].handlerPrint)
			return (hp_types[i].fn(list, buffer, flags, width, precision, size));

	if (hp_types[i].handlerPrint == '\0')
	{
		if (handlerPrint[*ind] == '\0')
			return (-1);
		len += write(1, "%%", 1);
		if (handlerPrint[*ind - 1] == ' ')
			len += write(1, " ", 1);
		else if (width)
		{
			--(*ind);
			while (handlerPrint[*ind] != ' ' && handlerPrint[*ind] != '%')
				--(*ind);
			if (handlerPrint[*ind] == ' ')
				--(*ind);
			return (1);
		}
		len += write(1, &handlerPrint[*ind], 1);
		return (len);
	}
	return (pc);
}
