#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "shell.h"
#define MAX_DIRS 100
/**
*
*
*
*
*/
int main(int ac, char **av)
{
    char *path;
  int i;
  char **str;
  size_t buffsize = 1024;
	char *buffer = malloc(buffsize * sizeof(char));
	int size;
	char **cmp;
	int count;
	char *token;
	char *dir;
	char *full_path;
	if (buffer ==NULL)
	  {
	    perror("Error");
	    exit (1);
	  }
while (!feof(stdin))
{
printf("$ ");
getline(&buffer, &buffsize, stdin);
str = malloc(buffsize * sizeof(char *));
if (str == NULL)
  {
    perror("ERROR");
		     exit (1);
  }
  count = 0;
 token = strtok(buffer, " ");
 while (token != NULL)
   {
     str[count] = malloc(strlen(token) + 1);
     strcpy(str[count], token);
     count++;
     token = strtok(NULL, " ");
   }
 path = getenv("PATH");
 cmp = malloc(MAX_DIRS *sizeof(char *));
 if (cmp == NULL)
   {
     perror("ERROR");
     exit(1);
   }
 dir = strtok(path, ":");
 i = 0;
 while (dir != NULL && i < MAX_DIRS)
   {
     cmp[i] = malloc(strlen(dir) + 1);
     strcpy(cmp[i], dir);
     i++;
     dir = strtok(NULL, ":");
   }
 for (i = 0; i < 6; i++)
   {
	 printf("%s\n", cmp[i]);
		 full_path = malloc(strlen(cmp[i]) + strlen(str[0]) + 2);
		 if (full_path == NULL)
		   {
		     perror("FAIL");
		     exit(1);
		   }
		 printf("%s, %s", str[0] cmp[i]);
		 full_path = find_file(str[0], cmp[i]);
		 if (execve(full_path, cmp, NULL) == -1);
		 {
		   perror("FAIL");
	     exit(1);
	       }
	 
	   
		 printf("%s", full_path);
   }
 printf("Finished\n");
 }
for (i = 0; i < MAX_DIRS; i++)
   {
     free(cmp[i]);
   }
 free(cmp);

 for (i = 0; i < count; i++)
   {
     free(str[i]);
   }
 free(str);

 free(full_path);
free(buffer);
   return (0);
}
