#include "shell.h"
void freearray(char **arr)
{
int n;
if (!arr)
return ;
for (n = 0; arr[n]; n++)
{
free (arr[n]), arr[n] = NULL;
}
free (arr), arr = NULL;
}
