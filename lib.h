#ifndef LIB_H
#define LIB_H

/* header files */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <fcntl.h>
#include <errno.h>

/* Global variable */
extern char **environ;

/* Macros */
#define BUFSIZE 256
#define TOKENSIZE 64
#define PRINT(c) (write(STDOUT_FILENO, c, _strlen(c)))
#define PROMPT "$ "
#define SUCCESS (1)
#define FAIL (-1)
#define NEUTRAL (0)

/* Struct */

/**
 * struct sh_data - Global data structure
 * @line: the line input
 * @args: the arguments token
 * @error_msg: the global path
 * @cmd: the parsed command
 * @index: the command index
 * @oldpwd: the old path visited
 * @env: the environnment
 *
 * Description: A structure contains all the variables needed to manage
 * the program, memory and accessability
 */
typedef struct sh_data
{
	char *line;
	char **args;
	char *cmd;
	char *error_msg;
	char *oldpwd;
	unsigned long int index;
	char *env;
} sh_t;
/**
 * struct builtin - Manage the builtin functions
 * @cmd: the command line on string form
 * @f: the associated function
 *
 * Description: this struct made to manage builtins cmd
 */
typedef struct builtin
{
	char *cmd;
	int (*f)(sh_t *data);
} blt_t;

int parse_line(sh_t *);
int process_cmd(sh_t *);
int read_line(sh_t *);
int split_line(sh_t *);



char *_strcat(char *first, char *second);
char *_strcpy(char *dest, char *source);
char *_strdup(char *str);
char *_strchr(char *str, char c);
int _strcmp(char *s1, char *s2);
int _strlen(char *str);



int free_data(sh_t *);
char *_memset(char *s, char byt, unsigned int n);
char *_memcpy(char *dest, char *src, unsigned int n);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);


void array_rev(char *arr, int len);
void *fill_an_array(void *a, int el, unsigned int len);
char *_getenv(char *path_name);
void index_cmd(sh_t *data);
void signal_handler(int signo);



int _atoi(char *c);
int intlen(int num);
int _isalpha(int c);
char *_itoa(unsigned int n);
int print_error(sh_t *data);
int write_history(sh_t *data);



int abort_prg(sh_t *data);
int change_dir(sh_t *data);
int check_builtin(sh_t *data);
int display_help(sh_t *data);
int handle_builtin(sh_t *data);



int is_builtin(sh_t *data);
int is_path_form(sh_t *data);
void is_short_form(sh_t *data);


#endif 