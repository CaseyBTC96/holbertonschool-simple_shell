#ifndef main_h
#define main_h
char* find_file(char *pattern, char *directoryPath);
char* abs_path(char *path, char *file);
void free_array(char *array);
void forkexec(char *file, char *directory);
#endif 
