#ifndef MAIN_H
#define MAIN_H

extern char **environ;

/**
 * struct builtin - contain a name and the function associated to a builtin
 * @name: the name of the builtin command
 * @action: the function to run when the bultin in found
 */
typedef struct builtin
{
	char *name;
	int (*action)(char **);
} builtin_t;

void free_arr(char *str);
void free_2D(char **str);

char *getinput(void);
char **strparse(char *str, char *delim);
char *search_path(char *command);
char *search_in_dir(char *command);
void execute(char *command, char **argv);
int search_builtin(char **argv);

char *_strdup(char *str);
char **strtow(char *str, char c);
char *_strcat(char *dest, char *src);
int _strlen(char *str);
char *str_concat(char *s1, char *s2);
int _atoi(char *num);
int _strcmp(char *s1, char *s2);
int _fprintf(int fd, char *format, ...);
int print_string(char *str, int fd);
int exit_shell(char **argv);
int print_env(char **argv);
#endif
