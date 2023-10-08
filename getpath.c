#include "shell.h"
char *getpath(char *command)
{
	char *path_envi, *cmd, *dir;
	int i;
	struct stat st;
	for(i=0; command[i]; i++)
	{ if (command[i] =='/')
		{ if (stat(command,&st) ==0)
			return (_strdup(command));
		return (NULL);
		}
	}
	path_envi =getenvi("PATH");
	if (!path_envi)
		return(NULL);
	dir = strtok(path_envi,":");
	while(dir)
	{ cmd = malloc(_strlen(dir) + _strlen(command) +2);
		if (cmd)
		{ _strcpy(cmd,dir);
		  _strcat(cmd,"/");
		  _strcat(cmd, command);
		  if (stat(cmd,&st)==0)
		  {free (path_envi);
			 return (cmd);
		  }
		  free(cmd), cmd=NULL;
		  dir =strtok(NULL,":");
		}
	}
	free(path_envi);
	return(NULL);
}
