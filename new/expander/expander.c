#include "expander.h"


int	check_dollar(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
	{
		if (str[i] == '$')
			return (1);
		i++;
	}
	return (0);
}

// ! la solution est de jouer avec les adresses des tokens

t_token	*expander(t_token *tokenized_tokens, char **env)
{
	t_lists_env	lists_env;
	char		**before_equal;
	char		**after_equal;
	char		**divided_by_dollar;

	lists_env = split_lists_env(env);
	before_equal = lists_env.before_equal;
	after_equal = lists_env.after_equal;
	while (tokenized_tokens != NULL)
	{
		if (tokenized_tokens->type == TOKEN_WORD)
		{
			if (check_dollar(tokenized_tokens->value))
			{
				divided_by_dollar = new_ft_split(tokenized_tokens->value, '\'');
				//divided_by_dollar = ft_split_double(divided_by_dollar, '$');
			}
		}
		//tokenized_tokens->value = *divided_by_dollar;
		tokenized_tokens = tokenized_tokens->next;
	}
	int i = 0;
	while(divided_by_dollar[i] != NULL)
	{
		printf("div by dollar final %d : %s\n", i + 1, divided_by_dollar[i]);
		i++;
	}
	printf("div by dollar final %d : %s\n", i + 1, divided_by_dollar[i]);
	(void)before_equal;
	(void)after_equal;
	(void)divided_by_dollar;
	free(divided_by_dollar);
	return (tokenized_tokens);
}


// echo hello users 'hi' how are you '$USER' doing $SHELL