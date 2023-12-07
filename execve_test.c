#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "shell.h"
int main(void)
{
  int i;
  size_t buffsize = 1024;
	char *buffer = (char *)malloc(buffsize * sizeof(char));
	char **new;
	int path_count;
	char *path;
	if (buffer == NULL)
	{
		perror("Error");
		exit(1);
	}

	while (!feof(stdin))
	{
		printf(" $ ");
		getline(&buffer, &buffsize, stdin);
		char **args = (char **)malloc(buffsize * sizeof(char *));
		if (args == NULL)
		{
			perror("Error");
			exit(1);
		}

		int count = 0;
		char *token = strtok(buffer, " \n");
		while (token != NULL)
		{
			args[count] = strdup(token);
			count++;
			token = strtok(NULL, " \n");
		}
		printf("INPUT:\n");
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
		    for (i = 0; i < count; i++)
		      {
			printf("%s\n", args[i]);
		      }
		    pid_t pid = fork();
		    if (pid < 0)
		      {
			perror("Fork Failed");
			exit(1);
		      }
		    else if (pid == 0)
		      {
		path = getenv("PATH");
		printf("%s\n", path);
		new = (char **)malloc(buffsize * sizeof(char *));
		if (new == NULL)
		  {
		    perror ("Error");
		    exit(1);
		  }
		path_count = 0;
		token = strtok(path, ":");
		while (token != NULL)
		  {
		    new[path_count] = strdup(token);
		    path_count++;
		    token = strtok(NULL, ":");
		  }
		printf("NEW PATH:\n");
		for (i = 0; i < path_count; i++)
		  {
		    printf("%s\n", new[i]);
		    char file_path[1024];
		snprintf(file_path, sizeof(file_path), "%s/%s", new[i], args[0]);
		if (access(file_path, F_OK) != -1)
		  {
		    printf("File %s exists!\n", file_path);
		_execute(file_path, args, new);
		  }
		else
	         {
		    printf("File Does not exist or cannot be accessed");
		 }
		  }
		for (i = 0; i < path_count; i++)
		  {
		    free(new[i]);
		  }
		free(new);
		exit(0);
		      }
		    else
		      {
			int status;
			waitpid(pid, &status, 0);
			if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
			  {
			    fprintf(stderr, "Child process failed with exit code %d\n", WEXITSTATUS(status));
			    exit(1);
			  }
		      }
		  }
		for (i = 0; i < count; i++)
		  {
		    free(args[i]);
		  }
		free(args);
}
	free(buffer);
return (0);
}
