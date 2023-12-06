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
int main(void)
{
  char path[] = "/some/path";
  char file[] = "example.txt";

  char *result = abs_path(path, file);
  printf("Absolute Path: %s\n", result);
  free(result);
  return (0);
}
