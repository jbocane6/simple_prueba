#ifndef _HEADER_SHELL_
#define _HEADER_SHELL_

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <string.h>
#ifndef _POSIX_SOURCE
#define _POSIX_SOURCE
#endif

#define err STDOUT_FILENO
#define DELIM " "
#define STRPATH _strtok(get_environ("PATH"), ":")

int include_char(char *str, char character);
int count_until(char *strUntil, char *str);
char *cp_until(char *strUntil, char *strToCopy);
int count_words(char *strDelim, char *str);
char **_strtok(char *str, char *delim);
int count(char *test);
char *readline();
void statPath(char **strfather);
void callExe(char **strfather);
char *get_environ(char *pathName);
char *combine(char *command, char **splitPath);

#endif
