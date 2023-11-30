#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
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
 for (i = 0; i < MAX_DIRS; i++)
   {
     if (cmp[i] != NULL)
       {
	 printf("%s\n", cmp[i]);
	 if (strcmp(cmp[i], str[0]) == 0)
	   {
	     child_pid = fork();
	     if (child_pid == 0)
	       {
		 full_path = malloc(strlen(cmp[i]) + strlen(str[0]) + 2);
		 if (full_path == NULL)
		   {
		     perror("FAIL");
		     exit(1);
		   }
		 strcpy(full_path, cmp[i]);
		 strcat(full_path, "/");
		 strcat(full_path, str[0]);
	       execve(full_path, cmp, NULL);
	       }
	     perror("FAIL");
	     exit(1);
	   }
	 else
	   {
	     wait(NULL);
	   }
	 break;
       }
   }
 }
 for (i = 0; i < count; i++)
   free(str[i]);
}
 free(buffer);
   return (0);
}
