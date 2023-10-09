#include "shell.h"
/**
*main-main function
*@ac:count of arguments
*@argv:a pointer to pointer to string
*
*Return:0 always (success)
*/
int main(int ac, char **argv)
{
char *line = NULL, **command = NULL;
int status = 0, idx = 0;
(void) ac;
while (1)
{
line = lire_ligne();
if (ligne == NULL)
{
if (isatty(STDIN_FILENO))
write(STDOUT_FILENO, "\n", 1)
return (status);
}
idx++;
command = tokenizer(ligne);
if (!command)
continue;
if (is_builtin(command[0]))
handle_builtin(command, argv, &status, idx);
else
status = _execute(command, argv, idx);
}
}
