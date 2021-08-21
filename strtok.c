#include "holberton.h"

#define TEST_TOK

int include_char(char *str, char character)
{
	if (!str || !*str)
		return (0);
	if (*str == character)
		return (1);
	return (include_char(str + 1, character));
}

int count_until(char *strUntil, char *str)
{
	if (!strUntil || !*strUntil || !str || !*str)
		return (0);
	if (!include_char(strUntil, *str))
		return (1 + count_until(strUntil, str + 1));
	return (0);
}

char *cp_until(char *strUntil, char *strToCopy)
{
	int count = count_until(strUntil, strToCopy) , i = 0;
	char *newStr = malloc(sizeof(char) * count);

	if (!newStr)
		return (NULL);

	for (i = 0; i < count; i++)
		newStr[i] = strToCopy[i];
	newStr[i] = '\0';
	return (newStr);
}

int count_words(char *strDelim, char *str)
{
	if (!str || !*str || !strDelim || !*strDelim)
	{
		return (0);
	}
	if (!include_char(strDelim, *str))
	{
		int sizeWorld = count_until(strDelim, str);
		return (1 + count_words(strDelim, str + sizeWorld));
	}
	return (count_words(strDelim, str + 1));
}

char **_strtok(char *str, char *delim)
{
	char **arrayWords;
	int indexWords = 0;
	int sizeWords = count_words(delim, str), i = 0;

	arrayWords = malloc(sizeof(char *) * sizeWords + 1);
	if (!arrayWords)
		dprintf(err, "ERROR malloc 1"),	exit(100);

	while (str[i])
	{
		if (!include_char(delim, str[i]))
		{
			arrayWords[indexWords] = cp_until(delim, str + i);
			i += count_until(delim, str + i);
			indexWords++;
		}
		else
			i++;
	}
	arrayWords[indexWords] = NULL;
	return (arrayWords);
}