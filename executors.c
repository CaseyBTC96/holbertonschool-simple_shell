#include "shell.h"

/**
 * _execute - Fork process and replace the child with a new  program
 * @arguments: string of arguments (tokens)
 * @argv: array of arguments
 * @exit_status: Exit status
 * Return: Always 1 (success)
 */
int _execute(char **arguments, char **argv, int *exit_status)
{
	pid_t pid;
	int status; /* this will be used with waitpid syscall */
	char *new_arguments;

	/* check if PATH exists and can be accessed, also tokenize PATH */
	new_arguments = validate_input(arguments, argv);
	if (strcmp(new_arguments, "Fail access") == 0)
		return  (1);
	pid = fork(); /* create a duplicate process (child) */
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
		return (1);
	}
	else /* parent process */
	{
		/* this is equivalent to wait(&status) */
		waitpid(-1, &status, 0);
		/* check if the child terminated normally */
		if (WIFEXITED(status))
			/* return the exit status of the child */
			*exit_status = WEXITSTATUS(status);
		/* evaluate first element of first token */
		if (arguments[0][0] != '/' && arguments[0][0] != '.')
			free(new_arguments);
		return (1);
	}
	return (1);
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
