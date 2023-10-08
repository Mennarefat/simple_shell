#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <fcntl.h>
#define DELIM "\t\n"

extern char **environ;


char **tokenizer(char *ligne);
char *lire_ligne(void);
char *_strdup(const char *str);
int _strcmp(char *s1, char *s2);
int _strlen(char *s);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
void freearray(char **arr);
int executer(char **command, char **argv);
char *getenvi(char *variable);

#endif
