#include "holberton.h"

extern char **environ;

int validateMainFunctions(char **strfather)
{
	if (strcmp(strfather[0], "exit") == 0)
		return (0);
	return (statPath(strfather));
}

int callExe(char **strfather)
{
	pid_t child;
	child = fork();

	if (child == -1)
	{
		perror("Error:");
		return (0);
	}
	if (child == 0)
	{
		if (execve(strfather[0], strfather, NULL) == -1)
			perror("Error");
		exit(0);
	}
	else
		wait(0);

	return (1);
}

int main(void)
{
	int cfather, flag = 1, size = 1024;
	char *strReceived, **strfather = NULL;

	while (flag > 0)
	{
		size = readline(&strReceived, &size);
		if (size > 0)
		{
			cfather = count_words(DELIM, strReceived);

			strfather = malloc(sizeof(char *) * cfather + 1);
			if (!strfather)
				dprintf(err, "ERROR malloc"), exit(100);

			strfather =_strtok(strReceived, DELIM);
			flag = validateMainFunctions(strfather);
			free(strReceived);
		}
	}
	return (0);
}
