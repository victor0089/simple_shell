#ifndef VICO_H
#define VICO_H

#define MAX_INPUT_LENGTH 1024
#define MAXARGS 128

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <dirent.h>
#include <signal.h>
#include <limits.h>
extern char **environ;


void hndmulti_cmd(char *input_buffer, char *multi_command[]);
void crt_process(char *argv_buffer[]);
void exche_cute(char *argv_buffer[], char *new_arg);
int buiin_cmd(char **argv);
/* code */
void inerive_mod(int bytes, char *input_buffer,
char *argv_buffer[], char *new_arg);
void nonive_mod(char *input_buffer, char *multi_command[],
char *argv_buffer[], char *new_arg);
/* code2 */
void crt_process(char *argv_buffer[]);
void exche_cute(char *argv_buffer[], char *new_arg);
int buiin_cmd(char **argv);
/* code 3 */
int _strlen(char *s);
void _strncpy(char *dest, char *scsr, int n);
int _strcmp(char *gh1, char *gh2);
int _atoi(char *s);
/* code4 */
void hndmulti_cmd(char *input_buffer, char *multi_command[]);
/* end of shell */
#endif
