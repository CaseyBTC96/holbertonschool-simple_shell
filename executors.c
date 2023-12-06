#include "shell.h"

/**
 * _execute - Fork process and replace the child with a new  program
 * @arguments: string of arguments (tokens)
 * @argv: array of arguments
 * @exit_status: Exit status
 * Return: Always 1 (success)
 */
int _execute(char *filename, char *const argv, char *const envp[])
{
	pid_t pid = fork(); /* create a duplicate process (child) */
	int status;
	if (pid == 0) /* child process */
	{
		/* execute a completley new program instead of the child */
		if (execve(new_arguments, argument, environ) == -1)
		{
			perror("execve fail");
			/* free (new_arguments) */
			exit(EXIT_FAILURE);
		}
	}
	else if (pid < 0)  /* check if fork fails */
	{
		perror("Error forking");
		free(new_arguments);
		return (-1);
	}
	else /* parent process */
	{
		/* this is equivalent to wait(&status) */
		waitpid(pid, &status, 0);
		/* check if the child terminated normally */
		if (WIFEXITED(status))
		    return (WEXITSTATUS(status);
		    else
		     return (-1);
	}
}
			      
/**
 * _execute_builtins - Choose from an array of builtin functions
 * @args: String of arguments (tokens)
 * @input_stdin: string from input
 * @argv: Array of argumentss
 * @exit_status: Exit status
 * Return: Status to stay or exit the main loop, 1 or 0
 */
int _execute_builtins(char **args, char *input_stdin, char **argv, int *exit_satus)
{
	int i = 0;

	/* builtin functions array of type 'structure choose_builltin' (see shell.h) */
	choose_builtins_t  options[] = {
		{"exit", _exit},
		{"env", _env},
		{"cd", _cd},
		{"setenv", _setenv},
		{"unsetenv", _unsetenv},
		{NULL, NULL}
	};

	while (options[i].name_builtin)
	{
		/* compare if args[0] matches the builtin function name */
		if (strcmp(options[i].name_builtin, args[0]) == 0)
		{
			/* return the pointer to  function (2nd member of array) and execute it */
			return ((int)((*options[i].func_builtin)(args, input_stdin, exit_status)));
		}
		i++;
	}
	/* if no builtin function is encountered execute a process */
	return (_execute(args, argv, exit_status));
}
