#include "vheadersh.h"
/**
 * st_tok - function tht hanes a sting
 * (skip spaces and splt it)
 * @delimiter: charer we wll use to splt string.
 * @str: string we will handle.
 * @argv: array that will save splitted string.
 * Return: void.
 */
void st_tok(char *str, char *delimiter, char *argv[])
{
char *frt_pr = NULL;
char *scnd_pr = NULL;
int argc = 0;
int lin;
if (str != NULL)
{
lin = _strlen(str);
while (lin > 0 && str[lin - 1] == ' ')
str[--lin] = '\0';
}
frt_pr = str;
while (*frt_pr && *frt_pr == ' ')
frt_pr++;
scnd_pr = frt_pr;
while (*frt_pr != '\0')
{
if (_strcmp(frt_pr, delimiter) == 0)
{
*frt_pr = '\0';
while (*(frt_pr + 1) == ' ')
frt_pr++;
argv[argc++] = scnd_pr;
scnd_pr = frt_pr + 1;
if (argc >= MAXARGS)
break;
}
frt_pr++;
}
argv[argc++] = scnd_pr;
argv[argc] = NULL;
}
