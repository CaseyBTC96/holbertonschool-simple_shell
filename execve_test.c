#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void)
{
	size_t buffsize = 1024;
	char *buffer = (char *)malloc(buffsize * sizeof(char));

	if (buffer == NULL)
	{
		perror("Error");
		exit (1);
	}

	while (!feof(stdin))
	{
		printf(" $ ");
		getline(&buffer, &buffsize, stdin);

		//tokenize the input command
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
		args[count] = NULL;

		//Print the tokenized command
		for (int i = 0; i < count; i++)
		{
			printf("%s\n", args[i]);
		}

		//Execute the command
		pid_t  pid = fork();

		if (pid == -1)
		{
			perror("Fork failed");
			exit(1);
		}

		if (pid == 0)
		{
			//Child Process
			char *argv[] = {"/bin/ls", "-l", "/usr/", NULL};

			printf("Before execve\n");

			if (execve(argv[0], argv, NULL) == -1)
			{
			perror("Execution failed");
			exit(1);
			}
		}
		else
		{
		//parent process
		wait(NULL);
		}

	//free allocated memory
		for (int i =  0; i < count; i++)
		{
			free(args[i]);
		}
	}

	free(buffer);
	return 0;
}
