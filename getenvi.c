#include "shell.h"
char *getenvi(char *variable)
{
	char *tcp, *cle , *val , *env;
	int i;

	for (i=0 ; environ[i]; i++)
	{
		tcp = _strdup(environ[i]);
		cle = strtok(tcp, "=");
		if(_strcmp(cle, variable)==0)
		{
			val = strtok(NULL, "\n");
			env = _strdup(val);
			free(tcp);
			return (env);
		}
		free(tcp) , tcp = NULL;
	}
	return (NULL);
}
int main()
{
	printf("%s \n", getenv("PATH"));
	return (0);
}

