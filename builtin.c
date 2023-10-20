#include "shell.h"
/**
*is_builtin-manage array of string
*@command:arr
*
*Return:0
*/
int is_builtin(char *command)
{
char *builtins[] = {
"exit", "envi", "setenvi", "cd", NULL
};
int e;
for (e = 0; builtins[e]; e++)
{
if (_strcmp(command, builtins[e]) == 0)
return (1);
}
return (0);
}
/**
*handle_builtin-check the program
*@command:pointer to pointer
*@argv:to main function
*@status:pointer to integer
*@idx:index
*
*/
void handle_builtin(char **command, char **argv, int *status, int idx)
{
if (_strcmp(command[0], "exit") == 0)
exit_shell(command, argv, status, idx);
else if (_strcmp(command[0], "env") == 0)
print_envi(command, status);

}
/**
*exit_shell-time to getout
*@command:pointer to pointer
*@status:integer
*@argv:argument to main
*@idx:index
*
*/
void exit_shell(char **command, char **argv,  int *status, int idx)
{
int exit_value = (*status);
char *index, mssg[] = ": exit Illegal number: ";
if (command[1])
{
if ((command[1]))
{
exit_value = _atoi(command[1]);
}
else
{
index = _itoa(idx);
write(STDERR_FILENO, argv[0], _strlen(argv[0]));
write(STDERR_FILENO, ": ", 2);
write(STDERR_FILENO, index, _strlen(index));
write(STDERR_FILENO, mssg, _strlen(mssg));
write(STDERR_FILENO, command[1], _strlen(command[1]));
write(STDERR_FILENO, "\n", 1);
free(index);
freearray(command);
(*status) = 2;
return;
}
}
freearray(command);
exit(exit_value);
}
/**
*print_envi-write environment
*@command:string
*@status:integer
*
*/
void print_envi(char **command, int *status)
{
int e;
(void) status;
for (e = 0; environ[e]; e++)
{
write(STDOUT_FILENO, environ[e], _strlen(environ[e]));
write(STDOUT_FILENO, "\n", 1);
}
freearray(command);
(*status) = 0;
}
