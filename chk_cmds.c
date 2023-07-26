#include "vheadersh.h"
/**
 * ad_binprefx - function full path to command.
 * @argv: array of arguments.
 * @new_arg: full command.
 * Return: void.
 */
void ad_binprefx(char *argv[], char *new_arg)
{
char *prx_pth = "/bin/";
size_t prx_ln;
size_t arg_len;
if (argv[0] == NULL)
	return;
prx_ln = _strlen(prx_pth);
arg_len = _strlen(argv[0]);
if (_strcmp(argv[0], prx_pth) == 0 || _strcmp(argv[0], "./") == 0
|| _strcmp(argv[0], "../") == 0)
return;
_strncpy(new_arg, prx_pth, prx_ln);
_strncpy(new_arg + prx_ln, argv[0], arg_len);
new_arg[prx_ln + arg_len] = '\0';
argv[0] = new_arg;
}
