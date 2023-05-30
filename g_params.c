#include "main.h"
#include "main.h"

/**
 * get_params - Calculates active params
 * @format: Formatted string in which to print the arguments
 * @i: take a parameter.
 * Return: params:
 */
int get_params(const char *format, int *i)
{
	int j, curr_i;
	int params = 0;
	const char params_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int params_ARR[] = {MINUS, PLUS, ZERO, HASH, SPACE, 0};

	for (curr_i = *i + 1; format[curr_i] != '\0'; curr_i++)
	{
		for (j = 0; params_CH[j] != '\0'; j++)
			if (format[curr_i] == params_CH[j])
			{
				params |= params_ARR[j];
				break;
			}

		if (params_CH[j] == 0)
			break;
	}

	*i = curr_i - 1;

	return (params);
}
