#include "holberton.h"


int statPath(char **strfather)
{
	struct stat st;
	/* validate if deault command is absolute path */
	/* example: strfather[0] = /bin/ls */
	if (stat(strfather[0], &st) == 0)
	{
		return (callExe(strfather));
	}
	else
	{
		strfather[0] = combine(strfather[0], STRPATH);
		if (strfather[0])
			return (statPath(strfather));
	}
	return (1);
}
