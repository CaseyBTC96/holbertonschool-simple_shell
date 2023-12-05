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
  char *home = getenv("HOME");
  if (home == NULL)
    {
      perror("getenv");
      return (NULL);
    }
  char combine[PATH_MAX];
  snprintf(combine, PATH_MAX, "%s/%s", home, directoryPath);
  if (strlen(combine) >= PATH_MAX)
    {
      perror("Path length exceeds buffer size");
      free (foundpath);
      return (NULL);
    }
  foundPath = (char *)malloc(PATH_MAX);
  if (foundPath == NULL)
    {
      perror("malloc failed");
      closedir(dr);
      return (NULL);
    }
  snprintf(foundPath, PATH_MAX, "%s/%s", combine, de->d_name);
  DIR *dr = opendir(combine);

  if (dr == NULL)
    {   perror("opendir");
  return NULL;
    }
  struct dirent *de;
  char *foundPath = NULL;

  while ((de = readdir(dr)) != NULL)
    {
      if (de->d_type == DT_REG && strstr(de->d_name, pattern) != NULL)
	{
	  foundPath = (char *)malloc(PATH_MAX);

	  if (foundPath == NULL)
	    {
	      perror("FAIL");
	      closedir(dr);
	      return (NULL);
	    }
	  snprintf(foundPath, PATH_MAX, "%s/%s", combine, de->d_name);
	  break;
	}
    }
  closedir(dr);
  return (foundPath);
}
char* main(void)
{
  char *result;
  char *pattern = "ls";
  char *directoryPath = "/bin";
    result = find_file(pattern, directoryPath);
    printf("%s\n", result);
    return (result);
}
