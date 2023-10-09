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
/**
*printerror-find errors
*@name:string
*@cmd:command
*@idx:index
*
*/
void printerror(char *name, char *cmd, int idx)
{
char *index, mssg[] = "! not found\n";
index = _itoa(idx);
write(STDERR_FILENO, name, _strlen(name));
write(STDERR_FILENO, ": ", 2);
write(STDERR_FILENO, index, _strlen(index));
write(STDERR_FILENO, ": ", 2);
write(STDERR_FILENO, cmd, _strlen(cmd));
write(STDERR_FILENO, mssg, _strlen(mssg));
free(index);
}
/**
*_itoa-check integer not zero
*@n:integer number
*
*Return:_strdup(buff)
*/
char *_itoa(int n)
{
char buff[20];
int e = 0;
if (n == 0)
buff[e++] = '0';
else
{
while (n > 0)
{
buff[e++] = (n % 10) + '0';
n /= 10;
}
}
buff[e] = '\0';
reverse_string(buff, e);
return (_strdup(buff));
}
/**
*reverse_string-returns length of string and reverse it
*@str:string
*@len:length
*
*/
void reverse_string(char *str, int len)
{
char tmp;
int start = 0;
int end = len - 1;
while (start < end)
{
tmp = str[start];
str[start] = str[end];
str[end] = tmp;
start++;
end--;
}
}
/**
*_atoi-return integer
*@str:array of string
*
*Return:num
*/
int _atoi(char *str)
{
int i, num = 0;
for (i = 0; str[i]; i++)
{
num *= 10;
num += (str[i] - '0');
}
return (num);
}
