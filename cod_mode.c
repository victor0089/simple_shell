#include "vheadersh.h"
/**
 * nonive_mod - fun that handles a cmmmd from non intective mode.
 * @input_buffer: buffer that save input line.
 * @multi_cmmmd: arry of cmds.
 * @argv_buffer: biffer that save arg.
 * @new_arg: full pah cmd.
 * Return: void
 */
void nonive_mod(char *input_buffer, char *multi_cmmmd[],
char *argv_buffer[], char *new_arg)
{
int bytes, ffd = 0;
char *cmmmd;
bytes = read(STDIN_FILENO, input_buffer, MAX_INPUT_LENGTH);
if (input_buffer[bytes - 1] == '\n')
input_buffer[bytes - 1] = '\0';
hndmulti_cmd(input_buffer, multi_cmmmd);
cmmmd = multi_cmmmd[0];
while (cmmmd != NULL)
{
st_tok(cmmmd, " ", argv_buffer);
exche_cute(argv_buffer, new_arg);
cmmmd = multi_cmmmd[++ffd];
}
}
/**
 * inerive_mod - function that handles a commmd from inive mode.
 * @bytes: num of bytes fromreding line.
 * @input_buffer: bur tt save inut line.
 * @argv_buffer: buffer that save arguments.
 * @new_arg: full path cmmmd.
 * Return: void.
 */
void inerive_mod(int bytes, char *input_buffer,
char *argv_buffer[], char *new_arg)
{
while (1)
{
write(STDOUT_FILENO, "$ ", 2);
bytes = read(STDOUT_FILENO, input_buffer, MAX_INPUT_LENGTH);
if (bytes == -1)
{
perror("Error reading from stdin");
continue;
}
else if (bytes == 0)
{
write(STDOUT_FILENO, "\n", 1);
break;
}
if (input_buffer[bytes - 1] == '\n')
input_buffer[bytes - 1] = '\0';
st_tok(input_buffer, "", argv_buffer);
if (argv_buffer[0] == NULL || *argv_buffer[0] == ' ')
continue;
exche_cute(argv_buffer, new_arg);
}
}
/**
 * crt_process - fun that creates a process and exectes a cmmd.
 * @argv_buffer: buffer that save arg.
 * Return: void.
 *
 */
void crt_process(char *argv_buffer[])
{
int eidf;
eidf = fork();
if (eidf == -1)
{
perror("fork failed");
exit(EXIT_FAILURE);
}
else if (eidf == 0)
{
execve(argv_buffer[0], argv_buffer, NULL);
perror(argv_buffer[0]);
exit(EXIT_FAILURE);
}
else
wait(NULL);
}
