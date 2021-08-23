#include "holberton.h"

char *combine(char *command, char **splitPath)
{
	int i = 0, j = 0, k = 0, sizeCommand, sizeSplitPath;
	int sizeTotal, flag = 0, flag2 = 0;
	struct stat st;
	char *commandCombine;
	while (splitPath[i])
	{
		sizeCommand = _strlen(command) + 1;
		sizeSplitPath = _strlen(splitPath[i]) + 1;
		sizeTotal = sizeCommand + sizeSplitPath;
		commandCombine = malloc(sizeof(char) * (sizeTotal));
		if (!commandCombine)
			return (NULL);
		for (j = 0; j < sizeTotal; j++)
		{
			if (splitPath[i][j] != '\0' && !flag2)
				commandCombine[j] = splitPath[i][j];
			else
			{
				flag2 = 1;
				if (!flag)
				{
					commandCombine[j] = '/';
					flag = 1;
				}
				else
				{
					commandCombine[j] = command[k];
					k++;
				}
			}
		}
		flag2 = 0;
		flag = 0;
		k = 0;
		commandCombine[j] = '\0';
		if (stat(commandCombine, &st) == 0)
		{
			arrayFree(splitPath);
			free(splitPath);
			return (commandCombine);
		}
		free(commandCombine);
		i++;
	}
	arrayFree(splitPath);
	free(splitPath);
	return (NULL);
}

int statPath(char **strfather)
{
	struct stat st;
	/* validate if deault command is absolute path */
	/* example: strfather[0] = /bin/ls */
	if (stat(strfather[0], &st) == 0)
	{
		return (callExe(strfather));
	}
	else
	{
		strfather[0] = combine(strfather[0], STRPATH);
		if (strfather[0])
			return (statPath(strfather));
	}
	return (1);
}
