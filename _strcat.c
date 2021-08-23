#include "holberton.h"

/**
 * _strcat - concatenates two strings
 * @dest: chain initial
 * @src: chain to join with *dest
 * Return: return pointer a dest
 */
char *_strcat(char *dest, char *src)
{
	int i = 0;
	int sizeDest = 0;
	int j = 0;
	char *concat = dest;

	while (dest[i] != '\0')
	{
		sizeDest++;
		i++;
	}
	while (src[j] != '\0')
	{
		dest[sizeDest + j] = src[j];
		j++;
	}
	dest[sizeDest + j] = src[j];

	return (concat);
}
