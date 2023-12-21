#include "vheadersh.h"

/**
 * main - program tht  Writ a smple UNIX cmd inrpreter.
 * Return: 0.
 */
int main(void)
{
ssize_t bytes = 0;
char input_buffer[MAX_INPUT_LENGTH];
char *mlti_cmd[MAXARGS];
char *argv_buffer[MAXARGS];
char new_arg[20];
if (isatty(STDIN_FILENO) == 1)
{
inerive_mod(bytes, input_buffer, argv_buffer, new_arg);
}
else
nonive_mod(input_buffer, mlti_cmd, argv_buffer, new_arg);
return (0);
}
