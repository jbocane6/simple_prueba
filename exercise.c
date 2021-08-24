#include "holberton.h"

extern char **environ;

void freestr(char **strfather, char *strReceived)
{
	arrayFree(strfather);
	free(strfather);
	free(strReceived);
}

int validateMainFunctions(char **strfather, char *strReceived, int character)
{
	int i = character;

	if (strcmp(strfather[0], "exit") == 0)
	{
		if (i > 1)
		{
			i = _atoi(strfather[1]);
			freestr(strfather, strReceived);
			exit(i);
		}
		else
		{
			freestr(strfather, strReceived);
			exit(0);
		}
	}
	if (strcmp(strfather[0], "cd") == 0)
	{
		chdir(strfather[1]);
		return (1);
	}
	if (strcmp(strfather[0], "env") == 0)
	{
		for (i = 0; environ[i]; i++)
		{
			write(err, environ[i], _strlen(environ[i]));
			write(err, "\n", 1);
		}
		return (1);
	}
	return (statPath(strfather));
}

char *move_last_until(char *string, char last)
{
	char *result = NULL;

	if (!string || !*string)
		return (NULL);
	result = move_last_until(string + 1, last);
	if (result != NULL)
		return (result);
	if (*string == last)
		return (string + 1);
	return (NULL);
}

int callExe(char **strfather)
{
	char stringDir[1024];
	pid_t child;
	child = fork();

	if (child == -1)
	{
		perror("Error:");
		return (0);
	}
	if (child == 0)
	{
		stringDir[0] = '\0';
		_strcat(stringDir, strfather[0]);
		strfather[0] = move_last_until(strfather[0], '/');
		if (execve(stringDir, strfather, NULL) == -1)
			perror("Error");
		exit(0);
	}
	else
		wait(0);

	return (1);
}

int main(void)
{
	int cfather, flag = 1, size = 1024, character = 0;

	while (flag > 0 && flag < 2)
	{
		char *strReceived = NULL, **strfather = NULL;
		character = readline(&strReceived, &size);
		if (character > 0)
		{
			character = count_words(DELIM, strReceived);
			strfather = _strtok(strReceived, DELIM);
			flag = validateMainFunctions(strfather, strReceived, character);
		}
		freestr(strfather, strReceived);
	}
	return (flag);
}
