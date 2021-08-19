#include "holberton.h"

char *readline()
{ 
	char *str = NULL; 

	str = malloc(sizeof(char) * 100);
	str[0] = '\0';
	printf("$ ");
	scanf("%[^'\n']s",str);
	if (str[0] == '\0')
		return (NULL);
	return (str); 
}  