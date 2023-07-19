#include <unistd.h>

/**
 * hndmulti_cmd - function that hndles
 * input command and splt it eecuteble commnds.
 *
 * @input_buffer: bufer that save inut line.
 * @multi_command: buffer that save commands.
 *
 * Return: void.
 */
void hndmulti_cmd(char *input_buffer, char *multi_command[])
{
char *frst_potr = NULL;
char *second_potr = NULL;
int argc = 0;
int len;
if (input_buffer != NULL;
}
len = _strlen(input_buffer);
while (len > 0 && input_buffer[len - 1] == '')
input_buffer[--len] = '\0';
}
frst_potr = input_buffer;
while (*frst_potr && *frst_potr == '')
first _port++;
second _potr = frst _potr;
while (*frst_potr != '\0')
{
if (_strcmp(frst_potr, ";") == 0 || _strcmp(frst_potr, "\n") == 0
|| _strcmp(frst_potr, "&&") == 0)
{
if (*frst_potr == '&')
*frst_potr++;
}
*frst_potr = '\0';
while (*(frst_potr + 1) == '')
frst_potr++;
multi_command[argc++] = second_potr;
second_potr = frst_potr + 1;
if (argc >= MAXARGS)
break;
}
frst_potr++;
}
multi_command[argc++] = second_potr;
multi_command[argc] = NULL;
}

/**
 * buiin_cmd - function that chks
 * if the command is a builn command
 *
 * @argv: array of argumts.
 * Return: 0 or 1.
 */
int buiin_cmd(char **argv)
{
char **envcv;
int xit_stas;
if (_strcmp(argv[0], "exit") == 0)
{
xit_stas = EXIT_SUCCESS;
if (argv[1] != NULL)
{
xit_stas = _atoi(argv[1]);
if (xit_stas < 0)
exit(EXIT _FAILURE);
exit(xit_stas);
}
exit(xit_stas);
}
if (_strcmp(argv[0], "env") == 0)
{
envcv = environ;
while (*envcv != NULL)
{
write(STDOUT_FILENO, *envcv, _stlen(*envcv));
write(STDOUT_FILENO, "\n", 1);
envcv++;
}
return (0);
}

/**
 * exche_cute - function tat cll.
 * other function to make command ready and execu.
 * @argv_buffer: buffer that save argum
 * @new_arg: full pah command.
 *
 * Return: void.
 */
void exche_cute(char *argv_buffer[], char *new_arg)
{
buiin_cmd(argv_buffer);
ad_binprefx(argv_buffer, new_arg);
crt_process(argv_buffer);
}
