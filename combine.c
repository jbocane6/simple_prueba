#include "holberton.h"

char *concatPlusPlus(int nVariables, ...)
{
	char buffer[1024];
	int i;
	char *string = NULL;
	va_list list;
	va_start(list, nVariables);

	for (i = 0; nVariables > 0; nVariables--)
		for (string = va_arg(list, char *); *string; i++)
			buffer[i] = *string++;
	buffer[i] = '\0';
	va_end(list);
	string = malloc(sizeof(char) * (i + 1));
	if (!string)
		return (NULL);
	while (i >= 0)
		string[i] = buffer[i], i--;

	return (string);
}

char *combine(char *command, char **splitPath)
{
	int i = 0, j = 0, k = 0, sizeCommand, sizeSplitPath;
	int sizeTotal, flag = 0, flag2 = 0;
	struct stat st;
	char *commandCombine;
	while (splitPath[i])
	{
		commandCombine = concatPlusPlus(3, splitPath[i], "/", command);
		if (!commandCombine)
			return (command);
		if (stat(commandCombine, &st) == 0)
		{
			arrayFree(splitPath);
			free(splitPath);
			free(command);
			return (commandCombine);
		}
		free(commandCombine);
		i++;
	}
	arrayFree(splitPath);
	free(splitPath);
	return (command);
}
