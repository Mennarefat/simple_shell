#include "shell.h"
int excuter(char **command , char **argv)
{
	pid_t fils;
	int status;

	fils = fork();
	if (fils== 0)
	{
		if (execve(command[0] , command, environ) == -1 )
		{
			perror(argv[0]);
			freearray(command);
			exit(0);
		}
	}else
	{
		waitpid(fils , $status , 0);
		freearray(command);
	}
	return(statu);
}
