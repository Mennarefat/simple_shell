#include "shell.h"

char *lire_ligne()
{
	char *ligne = NULL;
	size_t len = 0;
	ssize_t i;
	if (isatty(STDIN_FILENO))
	    write(STDOUT_FILENO, "$", 2);
	i = getline(&ligne , &len , stdin);
	if (i == 1)
	{
		free(ligne);
		return (NULL);
	}


	return(ligne);
}
