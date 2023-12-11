#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "shell.h"
int main(void)
{
  int result = 0;
  int i, j;
  size_t buffsize = 1024;
	char *buffer = (char *)malloc(buffsize * sizeof(char));
	char **new = NULL;
	int path_count;
	char *path = NULL;
	char **args = NULL;
	int count;
	char *token = NULL;
	  char file_path[1024];
	  pid_t pid;
	  int status;
	  if (buffer == NULL)
	{
		perror("Error");
		exit(1);
	}

	  while (1)
	{
	  printf("$ ");
	  fflush(stdout);
	  if (fgets(buffer, buffsize, stdin) == NULL)
	    {
	      break;
	    }
	  size_t len = strlen(buffer);
	  if (len > 0 && buffer[len - 1] == '\n')
	    {
	      buffer[len - 1] = '\0';
	    }
		count = 0;
		token = strtok(buffer, " \n");
		result = 0;
		while (token != NULL)
		{
		  args = realloc(args, (count + 1) * sizeof(char *));
		  if  (args == NULL)
		    {
		      perror("Error");
		      exit(EXIT_FAILURE);
		    }
			args[count] = strdup(token);
			count++;
			token = strtok(NULL, " \n");
		}
		if (strcmp(args[0], "env") == 0)
		  _env();
		else if (strcmp(args[0], "exit") == 0)
		  {
		    for (i = 0; i < count; i++)
		      {
			free(args[i]);
		      }
		    free(buffer);
		    free(args);
		  exit(0);
		  }
		else
		  {
		path = getenv("PATH");
		new = (char **)malloc(buffsize * sizeof(char *));
		if (new == NULL)
		  {
		    perror ("Error");
		    exit(1);
		  }
		path_count = 0;
		token = strtok(path, ":");
		result = 0;
		while (token != NULL)
		  {
		    new[path_count] = strdup(token);
		    path_count++;
		    token = strtok(NULL, ":");
		  }
		    if (access(args[0], X_OK) != -1)
		      {
			result = 1;
			printf("File found\n");
		      }
		    else
		      {
			memset(file_path, '\0', sizeof(file_path));
			for (j = 0; j < path_count; j++)
			  {
			snprintf(file_path, sizeof(file_path), "%s/%s", new[j], args[0]);
			if (access(file_path, X_OK) != -1)
			  {
			    result = 2;
			    printf("File found\n");
			    break;
			  }
			  }
		      }
		if (result > 0)
		  {
		    pid = fork();
		    if (pid == 0)
		      {
		    if (result == 1)
		      {
			if (execve(args[0], args, new) == -1)
			{
			  perror("File unaccessible");
			  exit(EXIT_FAILURE);
			}
		      }
		    else if (result == 2)
		      {
			if (execve(file_path, args, new) == -1)
			  {
			    perror("File unaccessible");
			    exit(EXIT_FAILURE);
			  }
		    exit(EXIT_SUCCESS);
		      }
		      }
		    if (pid < 0)
		      {
		    perror("Error");
		    exit(1);
		      }
		    else
		      {
			waitpid(pid, &status, 0);
			if (WIFEXITED(status))
			  {
			    continue;
			  }
			else
			  {
			    perror("Child process terminated abnormally");
			    return (-1);
			  }
		      }
		      }
		if (result == 0)
		  {
		    continue;
		  }
	   
		  }
	
		for (i = 0; i < path_count; i++)
		  {
		    free(new[i]);
		  }
		free(new);
		

		for (i = 0; i < count; i++)
		  {
		    free(args[i]);
		  }
		free(args);
	}
	free(buffer);
	exit(0);
	return (0);
}
