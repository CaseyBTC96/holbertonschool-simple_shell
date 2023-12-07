#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "shell.h"
int main(void)
{
  int result;
  int i;
  size_t buffsize = 1024;
	char *buffer = (char *)malloc(buffsize * sizeof(char));
	char **new;
	int path_count;
	char *path;
	char **args;
	int count;
	char *token;
	  pid_t pid;
	  char file_path[1024];
	  int status;
	if (buffer == NULL)
	{
		perror("Error");
		exit(1);
	}

	while (!feof(stdin))
	{
		printf(" $ ");
		getline(&buffer, &buffsize, stdin);
		args = (char **)malloc(buffsize * sizeof(char *));
		if (args == NULL)
		{
			perror("Error");
			exit(1);
		}

		count = 0;
		token = strtok(buffer, " \n");
		while (token != NULL)
		{
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
		while (token != NULL)
		  {
		    new[path_count] = strdup(token);
		    path_count++;
		    token = strtok(NULL, ":");
		  }
		for (i = 0; i < path_count; i++)
		  {
		    if ((result = _execute(args[0], args, new)))
		      {
			break;
		      }
		    else
		      {
			snprintf(file_path, sizeof(file_path), "%s/%s", new[i], args[0]);
		if (access(file_path, F_OK) != -1)
		  {
		_execute(file_path, args, new);
		  }
		else
	         {
		   continue;
		 }
		      }
		    if (result == 1)
		      break;
		  }
		for (i = 0; i < path_count; i++)
		  {
		    free(new[i]);
		  }
		free(new);
		exit(0);
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
