#include "holberton.h"

static int FLAG = 0;
extern char **environ;

void changeFlag(void)
{
	FLAG = 1;
}

void validateMainFunctions(char **strfather)
{
	if (strcmp(strfather[0], "exit") == 0)
	{
		changeFlag();
		exit(100);
	}
	statPath(strfather);
}

void callExe(char **strfather)
{
	pid_t child;
	child = fork();

	printf("SI llega al exenev\n");
	if (child == -1)
	{
		perror("Error:");
		return;
	}
	if (child == 0)
	{
		if (execve(strfather[0], strfather, NULL) == -1)
			perror("Error");
		exit(0);
	}
	else
		wait(0);
}

int main(void)
{
	int cfather;
	char *strReceived, **strfather = NULL;
	
	while (FLAG == 0)
	{
		strReceived = readline();
		if (!strReceived)
			exit(99);

		cfather = count_words(DELIM, strReceived);

		strfather = malloc(sizeof(char *) * cfather + 1);
		if (!strfather)
			dprintf(err, "ERROR malloc"), exit(100);

		strfather =_strtok(strReceived, DELIM);
		validateMainFunctions(strfather);
	}
	return (0);
}
