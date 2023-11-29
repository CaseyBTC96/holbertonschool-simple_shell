#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
*
*
*
*
*/
int main(int ac, char **av)
{
	char *str;
	size_t buffsize = 1024;
	char *buffer = malloc(buffsize * sizeof(char));
	int size;
	if (buffer == NULL)
{
perror("Error");
exit (1);
}
while (!feof(stdin))
{
printf("$ ");
size = getline(&buffer, &buffsize, stdin);
str = strtok(buffer, " ");
printf("characters: %d\n", size);

while (str != NULL)
{
printf("%s\n", str);
str = strtok(0, " ");
}
}
return (0);
}
