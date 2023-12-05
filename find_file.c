#include "shell.h"
#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <stdlib.h>
/**
*
*
*
*/
char* find_file(char *pattern, char *directoryPath)
{
  DIR *dr = opendir(directoryPath);

  if (dr == NULL)
    {   perror("opendir");
  return NULL;
    }
  struct dirent *de;
  char *foundPath = NULL;

  while ((de = readdir(dr)) != NULL)
    {
      if (de->d_type == DT_REG && strstr(de-d_name, pattern) != NULL)
	{
	  foundPath = (char *)malloc(PATH_MAX);

	  if (foundPath == NULL)
	    {
	      perror("FAIL");
	      closedir(dr);
	      return (NULL);
	    }
	  snprintf(foundPath, PATH_MAX, "%s/%s", directoryPath, de->d_name);
	  break;
	}
    }
  closedir(dr);
  return foundPath;
}
  
