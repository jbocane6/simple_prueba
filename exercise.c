#include "holberton.h"

extern char **environ;

int validateMainFunctions(char **strfather)
{
	if (strcmp(strfather[0], "exit") == 0)
		return (0);
	if (strcmp(strfather[0], "cd") == 0)
        chdir(strfather[1]);	
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
	int flag = 1, size;
	char *strReceived, **strfather = NULL;

	while (flag > 0)
	{
		size = readline(&strReceived, &size);
		if (size > 0)
		{
			strfather = _strtok(strReceived, DELIM);
			flag = validateMainFunctions(strfather);
			free(strReceived);
		}
	}
	return (0);
}
