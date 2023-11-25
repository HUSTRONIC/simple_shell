#ifndef _SHELL_H_
#define _SHELL_H_
#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>
#include <stdarg.h>
#include <ctype.h>

#define PATH_MAX_LENGTH 4096
#define PATH_SEPARATOR ":"
#define PROMPT "$ "
#define MAX_TOKENS 1024
#define BUFFER_SIZE 1024

void func_prompt(void);
char *func_get_put(void);
void f_l_put(void);
void *func_g_line(void);
int check_built(char **args);
int execute_buitlin(char *cmd, char **args);
void f_help(void);
void func_exit(char **args);
void _cd(char **args);
int f_set_env(char **args);
int f_unset_env(char **args);
int f_env(void);
int f_clear(char **args);
void func_sigint(int sig);
void func_sigquit(int sig);
void func_sigstp(int sig);
int func_exec(char **args);
char **tokennz(char *str, const char *delim);
char **tokennz_put(char *input);
char *f_g_env(const char *name);
char *func_g_path(void);
char *my_path(char *command);
void f_error(char **argv, char *arg);
void f_tok(char **ptr);
void f_path(void);
void f_put(char *str);
void f_puterror(char *err);
int f_strlen(const char *);
int f_strcmp(const char *s1, const char *s2);
int f_strncmp(const char *s1, const char *s2, size_t n);
char *f_strstr(char *haystack, char *needle);
char *f_strchr(char *s, char c);
char *f_strcpy(char *, char *);
char *f_strcat(char *, const char *);
char *f_strdup(const char *);
int _putchar(char);
unsigned int f_strspn(char *s, char *accept);
int f_atoi(const char *str);
char *f_memset(char *, char, unsigned int);
char *f_memcpy(char *dest, char *src, unsigned int n);
void *f_realloc(void *, unsigned int, unsigned int);
void *f_calloc(unsigned int nmemb, unsigned int size);

#endif
