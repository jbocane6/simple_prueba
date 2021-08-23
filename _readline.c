#include "holberton.h"

void ctrap(int sig)
{
	write(1, "\n", sig -1);
	write(1, "$ ", 2);
}

char *_realloc(char *ptr, unsigned int old_size, unsigned int new_size)
{
	char *newSizeMemory = NULL;
	unsigned int i = 0;

	if (old_size == new_size)
		return (ptr);
	if (ptr == NULL)
	{
		free(ptr);
		ptr = malloc(new_size);
		return (ptr);
	}
	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	newSizeMemory = malloc(new_size);
	if (newSizeMemory == NULL)
	{
		free(ptr);
		free(newSizeMemory);
		return (NULL);
	}
	for (i = 0; i < old_size; i++)
	{
		newSizeMemory[i] = ptr[i];
	}
	free(ptr);
	return (newSizeMemory);
}

int readline(char **lineptr, int *lineptrSize)
{
	(void)signal(SIGINT, ctrap);
	int i = 0, valRead = 0;
	char character = 0;

	write(1, "$ ", 2);
	*lineptr = malloc(sizeof(char) * *lineptrSize);
	if (!lineptr)
	{
		return (-1);
	}
	while (character != '\n')
	{
		valRead = read(STDIN_FILENO, &character, 1);
		if (valRead <= 0)
		{
			free(*lineptr);
			return (-1);
		}
		(*lineptr)[i] = character;
		i++;
		if (i >= *lineptrSize)
		{
			*lineptr = _realloc(*lineptr, *lineptrSize, *lineptrSize << 1);
			*lineptrSize = *lineptrSize << 1;
		}
	}
	(*lineptr)[i - 1] = '\0';
	return (i - 1);
}