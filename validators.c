#include "main.h"

/**
 * validate_input - Validate if PATH exists
 * @arguments: String of tokens
 * @argv: String of arguments from input
 * Return: A pointer to an array of the tokenized PATH directories
 **/
char *validate_input(char **arguments, char **argv __attribute__((unused)))
{
	char *new_arguments, *first, *slash_argument = "/";
	char **tokens_path, holder_env[1024];
	int i = 0;

	if (arguments[0][0] == '/' || arguments[0][0] == '.') /*check first element */
	{
		new_arguments = arguments[0]; /* point to the same address */
		if ((access(new_arguments, F_OK) == -1)) /* check if file exits */
		{
			fprintf(stderr, "%s: No such file or directory\n", arguments[0]);
			return ("Fail access");
		}
	}
