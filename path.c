#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


char* find_path(int argc, *path, char *argv[])
{
	if (argc != 2) 
	{ 
		fprintf(stderr, "usage: %s filename\n", argv[0]);
		return 1;
	}

	char *filename = argv[1];

	if (access(filename, X_OK) == 0) 
	{
		printf("%s\n", filename);
		return 0;
	}

	char *path_env = getenv("PATH");
	if (path_env == NULL)
	{
		fprintf(stderr, "Error: PATH environment variable not set. \n");
		return 1;
	}

	char *path_copy = strdup(path_env);
	char *token = strtok(path_copy, ":");

	while (token !=  NULL) 
	{
		char *full_path = (char *)malloc(strlen(token) + strlen(filename) + 2);
		sprintf(full_path, "%s/%s", token, filename);

		if (access(full_path, X_OK) == 0)
		{
			printf("%s\n", full_path);
			free(full_path);
			free(path_copy);
			return 0;
		}

		free(full_path);


		token = strtok(NULL, ":");
	}

	free(path_copy);

	fprintf(stderr, "%s: %s not found\n", argv[0], filename);
	return  1;
}
