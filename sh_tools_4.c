#include "lib_shell.h"

/**
 * is_number_positive - is number positive
 * @str: string
 * Return: int
*/
int is_number_positive(char *str)
{
	int i;

	if (!str)
		return (0);
	for (i = 0; str[i]; i++)
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
	}
	return (1);
}

/**
 * _atoi - transformer une chaîne représentant une valeur entière
 * @str: String
 * Return: int
*/
int _atoi(char *str)
{
	int i, num = 0;

	for (i = 0; str[i] ; i++)
	{
		num *= 10;
		num += (str[i] - '0');
	}
	return (num);
}
