#ifndef main_h
#define main_h
char* find_file(char *pattern, char *directoryPath);
char* abs_path(char *path, char *file);
void free_array(char *array);
/* built in functions */
int change_directory(char **args, char *input_stdin, int *exit_status);
int _setenv(char **args, char *input_stdin, int *exit_status);
int _unsetenv(char **args, char *input_stdin, int *exit_status);
int _env(char **args, char *input_stdin, int *exit_status);
int _exit(char **args, *input_stdin, int *exit_status);

#endif 
