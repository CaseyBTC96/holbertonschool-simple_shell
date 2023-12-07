#ifndef main_h
#define main_h
/**
 * struct choose_builtin - Builtin commands struct
 * @name_builin: Name of builtin command
 * @func_builtin: Pointer to builtin command functions
 */
typedef struct choose_builtin
{
        char *name_builtin;
        int (*func_builtin)(char **, char *, int *);

} choose_builtins_t;

/* built in functions */
int _env(char **args, char *input_stdin, int *exit_status);
int _execute(char *file, char *const args[], char *const env[]);
#endif 
