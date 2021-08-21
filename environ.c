#include "holberton.h"

extern char **environ;

char *get_environ(char *pathName)
{
    int i, j;
    for (i = 0; environ[i]; i++)
    {
        for (j = 0; pathName[j]; j++)
        {
            if (environ[i][j] != pathName[j])
                break;
        }
        if (pathName[j] == '\0' && environ[i][j] == '=')
            return (&environ[i][j +1]);
    }
    return (NULL);
}