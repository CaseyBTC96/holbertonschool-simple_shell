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
int _env(char **args, char *input_stdin, int *exit_status)
{
	int i = 0;

	(void)args;
	(void)input_stdin;
	(void)exit_status;

	if (environ[i] == NULL)
	{
		printf("%s", "The built in env is empty");
		return (1);
	}
	for (i = 0; environ[i]; i++)
		printf("%s\n", environ[i]);

	return (1);
}

/**
 * _exit - Function exit built in
 * @args: arguments
 * @input_stdin: input of stdin
 * @exit_status: exit status
 * Return: Exit success
 */
int _exit(char **argss, char *input_stdin, int *exit_status)
{
	int ouput_exit = 0;

	(void)args;
	(void)input_stdin;
	(void)exit_status;

	if (args[1] == NULL)
	{
		free(args);
		free(input_stdin);
		exit(*exit_status);
	}
	if (ags[2] != NULL)
	{
		fprintf(stderr, "exit: too many arguments\n");
		return (0);
	}
	output_exit = atoi(args[1]);
	free(args);
	free(input_stdin);
	exit(output_exit);
}
