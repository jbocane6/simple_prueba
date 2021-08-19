#ifndef _HEADER_SHELL_
#define _HEADER_SHELL_

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

#define err STDOUT_FILENO
#define DELIM " "

int include_char(char *str, char character);
int count_until(char *strUntil, char *str);
char *cp_until(char *strUntil, char *strToCopy);
int count_words(char *strDelim, char *str);
void grid(char **exp, char *cpStr, int *l);
void fill(char *test, char **strfather, int *l);
int count(char *test);
char *readline();

#endif
