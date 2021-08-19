#include "holberton.h"

void callchildren(char **strfather)
{
    pid_t child;

    for (int i = 0; i < 5; i++)
    {
        child = fork();
        if (child == -1)
        {
            perror("Error:");
            return;
        }
        if (child == 0)
        {
            printf("prueba %d\n", i + 1);
            if (execve(strfather[0], strfather, NULL) == -1)
                perror("Error");   /* execve() returns only on error */
            exit(0);
        }
        else
            wait(0);
    }
    
}

int main()
{
    int i = 0, cfather = 0, l = 0;
    char *test = "/bin/ls -l /tmp/", *strCopy = NULL;
    char **strfather = NULL;

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
    strfather = malloc(sizeof(char *) * cfather + 1);
	if (!strfather)
        dprintf(err, "ERROR malloc"), exit(100);

    i = 0;
	while (test[i])
	{
		if (!include_char(DELIM, test[i]))
		{
			strCopy = cp_until(DELIM, test + i);
            grid(strfather, strCopy, &l);
			i += count_until(DELIM, test + i);
		}
		else
			i++;
	}
	strfather[l] = NULL;
    
    callchildren(strfather);

 return (0);
}