#include "holberton.h"

void ctrap(int sig)
{
	write(1, "\n", sig -1);
	write(1, "$ ", 2);
}

char *readline()
{ 
	char *str = NULL;
	
	(void)signal(SIGINT, ctrap);
	str = malloc(sizeof(char) * 100);
	str[0] = '\0';
	write(1, "$ ", 2);
	scanf("%[^'\n']s",str);
	if (str[0] == '\0')
		return (NULL);
	return (str); 
}  