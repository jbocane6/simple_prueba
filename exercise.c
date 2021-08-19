#include "holberton.h"

int count(char *test)
{
	int i = 0, cfather = 0;

	while (test[i])
	{
		if (!include_char(DELIM, test[i]))
		{
			cfather += count_words(DELIM, test + i);
			break;
		}
		else
			i++;
	}
	return (cfather);
}

void fill(char *test, char **strfather, int *l)
{
	int i = 0;
	char *strCopy = NULL;

	while (test[i])
	{
		if (!include_char(DELIM, test[i]))
		{
			strCopy = cp_until(DELIM, test + i);
			grid(strfather, strCopy, l);
			i += count_until(DELIM, test + i);
		}
		else
			i++;
	}
}

void callchildren(char **strfather)
{
	pid_t child;

	/*for (int i = 0; i < 5; i++)
	{*/
		child = fork();
		if (child == -1)
		{
			perror("Error:");
			return;
		}
		if (child == 0)
		{
			/*printf("prueba %d\n", i + 1);*/
			if (execve(strfather[0], strfather, NULL) == -1)
				perror("Error");
			exit(0);
		}
		else
			wait(0);
	/*}*/

}

int main(void)
{
	int cfather, l = 0;
	char *test;
	char **strfather = NULL;

	test = readline();
	if (!test)
		dprintf(err, "ERROR"), exit(99);
	
	cfather = count(test);

	strfather = malloc(sizeof(char *) * cfather + 1);
	if (!strfather)
		dprintf(err, "ERROR malloc"), exit(100);

	fill(test, strfather, &l);
	strfather[l] = NULL;

	callchildren(strfather);

	return (0);
}
