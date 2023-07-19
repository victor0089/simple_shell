#define _VICO_JJ_H
#ifndef _VICO_JJ_H
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void hndmulti_cmd(char *input_buffer, char *multi_command[]);
void crt_process(char *argv_buffer[]);
void exche_cute(char *argv_buffer[], char *new_arg);
int buiin_cmd(char **argv);
