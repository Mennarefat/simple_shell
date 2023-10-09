#include "shell.h"
/**
*excuter-checks the program
*@command:pointer to pointer to string
*@argv:the argument vector from main()
*@idx:integer
*
*Return:status
*/
int excuter(char **command, char **argv, int idx)
{
char *f_cmd;
pid_t fils;
int status;
f_cmd = _getpath(command[0]);
if (!f_cmd)
{
printerror(argv[0], command[0], int idx);
freearray(command);
return (127);
}
fils = fork();
if (fils == 0)
{
if (execve(f_cmd, command, environ) == -1)
{
free(f_cmd), f_cmd = NULL;
freearray(command);
}
}
else
{
waitpid(fils, status, 0);
freearray(command);
free(f_cmd), f_cmd = NULL;
}
return (WEXITSTATUS(status));
}
