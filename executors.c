#include "shell.h"
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
/**
 * _execute - Fork process and replace the child with a new  program
 * @arguments: string of arguments (tokens)
 * @argv: array of arguments
 * @exit_status: Exit status
 * Return: Always 1 (success)
 */
int _execute(char *file, char *const args[], char *const env[])
{
  pid_t pid = fork(); /* create a duplicate process (child) */
	int status;
	if (pid == 0) /* child process */
	{
		/* execute a completley new program instead of the child */
	  if (execve(file, args, env) == -1)
		{
			perror("execve fail");
			/* free (new_arguments) */
			exit(EXIT_FAILURE);
		}
	}
	else if (pid < 0)  /* check if fork fails */
	{
		perror("Error forking");
		return (-1);
	}
	else /* parent process */
	{
		/* this is equivalent to wait(&status) */
		waitpid(pid, &status, 0);
		/* check if the child terminated normally */
		if (WIFEXITED(status))
		  return (WEXITSTATUS(status));
		    else
		     return (-1);
	}
	return (1);
}
	
