#include "shell.h"
/**
*_strdup-checks the end of the string that is not NULL
*@str:constant array of string
*
*Return:pointer to string
*/
char *_strdup(const char *str)
{
char *ptr;
int n, len = 0;
if (str == NULL)
return (NULL);
while (*str != '\0')
{
len++;
str++;
}
str = str - len;
ptr = malloc(sizeof(char) * (len + 1));
if (ptr == NULL)
return (NULL);
for (n = 0; n <= len; n++)
ptr[n] = str[n];
return (ptr);
}
/**
*_strcmp-to compare between two strings
*@s1:the first string
*@s2:the second string
*
*Return:cmp
*/
int _strcmp(char *s1, char *s2)
{
int cmp;
cmp = (int)*s1 - (int)*s2;
while (*s1)
{
if (*s1 != *s2)
break;
s1++;
s2++;
cmp = (int)*s1 - (int)*s2;
}
return (cmp);
}
/**
*_strlen-returns length of the string
*@s:the string
*
*Return:integer length of the string
*/
int _strlen(char *s)
{
int len = 0;
while (s[len])
len++;
return (len);
}
/**
*_strcat-concatenates two strings
*@dest:the destination
*@src:the source
*
*Return:pointer to dest
*/
char *_strcat(char *dest, char *src)
{
char *p = dest;
while (*p)
p++;
while (*src)
{
*p = *src;
p++;
src++;
}
*p = *src;
return (dest);
}
/**
*_strcpy-copies the string
*@dest:the destination
*@src:the source
*
*Return:pointer to destination
*/
char *_strcpy(char *dest, char *src)
{
int n = 0;
while (src[n])
{
dest[n] = src[n];
n++;
}
dest[n] = '\0';
return (dest);
}

