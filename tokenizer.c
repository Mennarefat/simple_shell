#include "shell.h"
char *tokenizer(char *ligne)
{
char *token = NULL, tmp = NULL;
char **command = NULL;
int cpt = 0, i = 0;
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
command[i] = _strdup(token);
token = strtok(NULL, DELIM);
i++;
}
free(ligne), ligne = NULL;
command[i] = NULL;
return (command);
}
