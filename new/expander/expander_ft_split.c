#include "expander.h"

// size_t	ft_strlen(const char *s)
// {
// 	size_t	i;

// 	s = (char *) s;
// 	i = 0;
// 	while (s[i] != '\0')
// 	{
// 		i++;
// 	}
// 	return (i);
// }

int ft_countword(const char *s, char c)
{
    int count = 0;
    while (*s)
    {
        while (*s == c)
            s++;
        if (*s)
            count++;
        while (*s != c && *s)
            s++;
    }
    return count;
}

char *fill_the_word(char *str, int end, int start , char *lst)
{
    int i;

    i = 0;
    while(i < end - start)
    {
        lst[i] = str[start + i];
        i++;
    }
    lst[i] = 0;
    return(lst);
}

char **ft_split_2(char *str, char c)
{
    char **lst;
    int i;
    int j;
    int reset;

    reset = 0;
    j = 0;
    lst = (char **)malloc((ft_countword(str, c) + 1) * sizeof(char *));
    if (!str || !lst)
        return NULL;
    i = 0;
    while (str[i] != '\0')
    {
        while ((reset > 0 && str[i] != c) || reset == 0)
        {
            i++;
            reset++;
            if (str[i] == 0)
              break;
        }
        lst[j] = calloc (reset + 1, sizeof(char));
        lst[j] = fill_the_word(str, i, (i - reset), lst[j]);
        j++;
        reset = 0;
    }
    lst[j] = NULL;
	//printf("in ft_split\n");
	int k = 0;
	while(lst[k])
	{
		printf("ft split strings %s\n", lst[k]);
		k++;
	}
    return (lst);
}