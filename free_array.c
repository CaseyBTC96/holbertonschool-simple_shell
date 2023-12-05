#include "shell.h"
/**
*
*
*
*
*/
void free_array(char *array, int count)
{
int i;
for (i = 0; i < count; i++)
{
free(array[i]);
}
free(array)
}
void main(void)
{
char array[] = {"hi", "my", "name", "is", "Elijah"};
int count = strlen(array);
array = malloc(strlen(array));
if (array == NUll)
{
perror ("Memory allocation error");
exit(EXIT_FAILURE);
}
free_array(array, count);
}