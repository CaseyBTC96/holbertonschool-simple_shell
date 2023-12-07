#include "shell.h"
#include <stdlib.h>
#include <stdio.h>
/**
 * _env - Function that print environment
 * @args: arguments
 * @input_stdin: input of stdin
 * @exit_status: exit status
 * Return: Always 1 (success)
 */
void _env(void)
{
  extern char **environ;
  
  for (char **env = environ; *env != NULL; env++)
		printf("%s\n", *env);
}
       
