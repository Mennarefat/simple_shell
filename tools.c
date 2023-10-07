#include "shell.h"
/**
*freearray-function to free array of string
*
*@arr:array of string
*/
void freearray(char **arr)
{
int n;
if (!arr)
return;
for (n = 0; arr[n]; n++)
{
free(arr[n]), arr[n] = NULL;
}
free(arr), arr = NULL;
}
