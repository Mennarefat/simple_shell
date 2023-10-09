#include "shell.h"
/**
*_getpath-get the path of the files
*@command:array of string
*
*Return:NULL
*/
char *getpath(char *command)
{
char *path_envi, *f_cmd, *dir;
int i;
struct state st;
for (i = 0; command[i]; i++)
{
if (command[i] == '/')
{
if (state(command, &st) == 0)
return (_strdup(command));
return (NULL);
}
}
path_envi = getenvi("PATH");
if (!path_envi)
return (NULL);
dir = strtok(path_envi, ":");
while (dir)
{
f_cmd = malloc(_strlen(dir) + _strlen(command) + 2);
if (f_cmd)
{
_strcpy(f_cmd, dir);
_strcat(f_cmd, "/");
_strcat(f_cmd, command);
if (state(f_cmd, &st) == 0)
{
free(path_envi);
return (f_cmd);
}
free(f_cmd), f_cmd = NULL;
dir = strtok(NULL, ":");
}
}
free(path_envi);
return (NULL);
}
