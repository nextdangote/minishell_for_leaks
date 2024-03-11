#include "expander.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	s = (char *) s;
	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

size_t	ft_strncpy(char *dst, const char *src, size_t size)
{
	size_t	src_len;
	size_t	i;

	src_len = 0;
	i = 0;
	// Calculate the length of the source string
	while (src[src_len] != '\0')
	{
		src_len++;
	}
	// Copy characters from src to dst, up to size characters
	while (i < size && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	// If there's still space in dst, pad with null characters
	while (i < size)
	{
		dst[i] = '\0';
		i++;
	}
	// Return the length of the source string
	return (src_len);
}

char	*ft_strdup(const char *s1)
{
	char	*nouveau;
	int		i;
	int		longueur;

	i = 0;
	longueur = ft_strlen(s1);
	nouveau = (char *)malloc(sizeof(char) * (longueur + 1));
	if (!nouveau)
	{
		return (NULL);
	}
	while (s1[i] != '\0')
	{
		nouveau[i] = s1[i];
		i++;
	}
	nouveau[i] = '\0';
	return (nouveau);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	len;
	size_t	j;

	j = 0;
	len = ft_strlen(s);
	if (s[j] == (char)c)
	{
		return ((char *)&s[j]);
	}
	while (s[j] != (char)c && j < len)
	{
		j++;
		if (s[j] == (char)c)
		{
			return ((char *)&s[j]);
		}
	}
	return (NULL);
}

// Function to split environment variables into two lists
void	create_lists(char ***list_before_equal, char ***list_after_equal,
		char **env)
{
	int		i;
	char	*equal_sign;
	size_t	len;

	i = 0;
	while (env[i] != NULL)
	{
		equal_sign = ft_strchr(env[i], '=');
		if (equal_sign != NULL)
		{
			// Calculate the length of substring before '='
			len = equal_sign - env[i];
			// Allocate memory and copy substring before '='
			(*list_before_equal)[i] = malloc((len + 1) * sizeof(char));
			if ((*list_before_equal)[i] == NULL)
			{
				printf("Memory allocation failed\n");
				exit(EXIT_FAILURE);
			}
			ft_strncpy((*list_before_equal)[i], env[i], len);
			(*list_before_equal)[i][len] = '\0';
			// Allocate memory and copy substring after '='
			(*list_after_equal)[i] = ft_strdup(equal_sign + 1);
			if ((*list_after_equal)[i] == NULL)
			{
				perror("Memory allocation failed\n");
				exit(EXIT_FAILURE);
			}
		}
		i++;
	}
	(*list_before_equal)[i] = NULL; // Null-terminate the lists
	(*list_after_equal)[i] = NULL;
    
}

t_lists_env	split_lists_env (char **env)
{
    t_lists_env list_to_give_back;
	int count;

    count = 0;
	while (env[count] != NULL)
		count++;

	// Allocate memory for lists
	char **list_before_equal = calloc(count + 1, sizeof(char *));
	char **list_after_equal = calloc(count + 1, sizeof(char *));
	if (list_before_equal == NULL || list_after_equal == NULL)
	{
		printf("Memory allocation failed\n");
		exit(EXIT_FAILURE);
	}

	// Create lists
	create_lists(&list_before_equal, &list_after_equal, env);
    list_to_give_back.before_equal = list_before_equal;
    list_to_give_back.after_equal = list_after_equal;
	return (list_to_give_back);
}
