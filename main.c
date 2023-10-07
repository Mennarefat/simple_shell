#include "shell.h"
/**
*main-main function
*@ac:count of arguments
*@av:arguments
*Return:0 always (success)
*/
int main(int ac,char **argv)
{
char *line = NULL, **command = NULL;
int i, status = 0;
(void) ac;
/**(void) argv;*/
while (1)
{
line = lire_ligne();
if (ligne == NULL)
{
if (isatty(STDIN_FILENO))
write(STDOUT_FILENO, "\n", 1)
return (status);
command = tokenizer(ligne);
if (!command)
continue;
/*for (i = 0; command[i]; i++)
{
printf("%%s\n", command[i]);
free(command[i]), command[i] = NULL;
}
free(command), command = NULL;*/
status = _execute(command, argv);
}
}
