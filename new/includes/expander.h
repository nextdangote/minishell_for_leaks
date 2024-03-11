#ifndef EXPANDER_H
# define EXPANDER_H

# include "lumumbash.h"
# include <dirent.h>
# include <termios.h>
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>
# include <string.h>
# include <stdio.h>
# include <ctype.h>

typedef struct s_lists_env
{
	char **before_equal;
	char **after_equal;
} t_lists_env;


int			ft_check_expand(char *str, int i, char **env);
char		*ft_find_env_var_part2(char *str);
char		**ft_split_2(char *str, char c);
char		**new_ft_split(char *str, char c);
char        **ft_split_double(char **str, char c);
int         check_if_expand(char *str, char **before_equal , char *c);
t_lists_env	split_lists_env (char **env);
t_token		*expander(t_token *tokenized_tokens, char **env);

// utils
char		*ft_strdup(const char *s1);
size_t		ft_strlen(const char *s);
int			ft_strncmp(char *s1, char *s2, size_t n);
char		*ft_strchr(const char *s, int c);

#endif