#include "libft/libft.h"
#include "libftprintf/ft_printf.h"
#include <stdio.h>
#include <unistd.h>
#include <errno.h>

#define FILE1 1
#define FILE2 4
#define CMD1 2
#define CMD2 3

char* ft_joinpath(char *s1, char *s2);
char* search_in_path(char *bin, char **path_env);
char** ft_find_path_env(char **envp);
char* get_bin_fullpath(char *bin, char **envp);
void ft_free_array(char **arr);