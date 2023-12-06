#include "shell.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
/**
 *
 *
 *
 *
 */
char *abs_path(char *path, char *file)
{
  char *print = malloc(strlen(path) + strlen(file) + 2);
  if (print == NULL)
    {
      perror("Memory Allocation error");
      exit(EXIT_FAILURE);
    }
  strcpy(print, path);
  strcat(print, "/");
  strcat(print, file);
  return (print);
}
