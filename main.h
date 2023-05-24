#ifndef MAIN_H
#define MAIN_H

<<<<<<< HEAD
void free_arr(char *str);
void free_2D(char **str);
char *getinput(void);
char **strparse(char *str, char *delim);
char *search_path(char *command, char **env);
char *search_in_dir(char *command, char **env);
char *_strdup(char *str);
char **strtow(char *str, char c);
char *_strcat(char *dest, char *src);
int _strlen(char *str);
char *str_concat(char *s1, char *s2);
void execute(char *command, char **argv, char **env);
=======
char *my_strtok(char *inputString, char *delim);
size_t my_getline(char *buf, FILE *stream, size_t size);
int print(char *str, ...);
>>>>>>> 9ff22e1eabc2437ac0d064027e9f28e0fb707e39

#endif
