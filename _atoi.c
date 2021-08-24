#include "holberton.h"

int _atoi(char *s)
{
    int numero = 0;

    for (int i = 0; s[i]; i++)
    {
        numero = (numero * 10) + (s[i] - '0');
    }
	return (numero);
}