#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define err STDOUT_FILENO

/**
 * grid - assing size in malloc and save information of cpStr in exp
 * @exp: pointer double
 * @cpStr: Information to copy
 * @l: Pointer to position of exp
 * @i: Increment
 * Return: Without return
 */
void grid(char **exp, char *cpStr, int *l, int *i)
{
	int k;

	exp[*l] = malloc(sizeof(char) * (*i + 1));
	if (!exp[*l])
	{
		printf("ERROR malloc 3");
		exit(100);
	}
	for (k = 0; k < *i; k++)
		exp[*l][k] = cpStr[k];
	exp[*l][k] = '\0';
	*l += 1;
	*i = 0;
}

/**
 * _strtok - split a chain of characters
 * @str: String to split
 * @delim: delimitador to use in str
 * Return: Array bidimentional with strings split
 */
char **_strtok(char *str, const char *delim)
{
	char *cpStr;
	char **exp;
	int i = 0, j = 0, k, l = 0, args = 1;

	for (i = 0; str[i]; i++)
	{
		if ((str[i] == delim[0] || str[i] == delim[0]) && str[i + 1] != '\0')
			args++;
	}

	exp = malloc(sizeof(char *) * args + 1);
	if (!exp)
	{
		printf("ERROR malloc 1");
		exit(100);
	}

	cpStr = malloc(sizeof(char) * strlen(str));
	if (!cpStr)
	{
		printf("ERROR malloc 2");
		exit(100);
	}

	i = 0;
	while (str[j])
	{
		if (str[j] != delim[0] || str[j] != delim[1])
		{
			cpStr[i] = str[j];
			i++;
		}
		else
			grid(exp, cpStr, &l, &i);
		j++;
	}
	if (i > 0)
		grid(exp, cpStr, &l, &i);
	exp[l] = '\0';
	return (exp);
}
