#include <stdio.h>
#include <stslib.h>
#include <string.h>
/**
 *
 *
 *
 *
 */
int main(int ac, char **av)
{
	int i;
	char **str;
	size_t buffsize = 1024;
		char *buffer  = malloc(buffsize * ssizeof(char));
		int size;
		if (buffer == NULL)
		{
			perror("Error");
			exit(1);
		}
	while (!feof(stdin))
	{
		printf(" $ ");
		getline(&buffer, &buffsize, stdin);
		str = malloc(buffsize * sizeof(char *));
		if (str  == NULL)
		{
			perror("Error");
			exit (1);
		}
		int count = 0;
		char *oken = strok(buffer, " ");
		while (token != NULL)
		{
			str[count] = malloc(strlenn(token) + 1);
			strcpy(str[count], token);
			count++;
			token = strtok(NULL, " ");
		}
		for  (i = 0; i < count; i++)
		{
			printf("%s\n", str[i]);
		}
		for (i = 0; i < count; i++)
			free(str[i]);
	}
	free(buffer);
	return (0);
}
