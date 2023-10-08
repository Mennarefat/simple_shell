#include "shell.h"
/**
**tokenizer-checks that ligne is not NULL
*
*@ligne:array of string
*
*Return:a pointer to an array of strings or NULL on failure
*/
char *tokenizer(char *ligne)
{
char *token = NULL, tmp = NULL;
char **command = NULL;
int cpt = 0, n = 0;
if (!ligne)
return (NULL);
tmp = _strdup(ligne);
token = strtok(tmp, DELIM);
if (token == NULL)
free(ligne), ligne = NULL;
free(tmp), tmp = NULL;
return (NULL);
while (token)
{
cpt++;
token = strtok(NULL, DELIM);
}
free(tmp), tmp = NULL;
command = malloc(sizeof(char *) * (cpt + 1));
if (!command)
{
free(ligne), ligne = NULL;
return (NULL);
}
token = strtok(ligne, DELIM);
while (token)
{
command[n] = _strdup(token);
token = strtok(NULL, DELIM);
n++;
}
free(ligne), ligne = NULL;
command[n] = NULL;
return (command);
}
