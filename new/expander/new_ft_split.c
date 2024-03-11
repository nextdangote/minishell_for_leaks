#include "expander.h"
#include <ctype.h>

int count_words(char *str) 
{
    int count = 0;
    //int inside_quotes = 0; // Flag to track whether inside single quotes
    int i = 0;

    while (str[i] != '\0') 
    {
        if (str[i] == '\'') 
        {
            i++;
            while(str[i] != '\'' && str[i] != '\0')
                i++;// Toggle the flag
            count++;
        } 
        else if (str[i] != '\'') 
        {
            while (str[i] != '\'' && str[i] != '\0')
                i++;
            count++; // Increment word count if not inside single quotes and space is found
        }
    }

    return count;
}

//!!!!! I need to malloc here
// "$USER$hello.    hello'$USER'  yo$USER"
char    *ft_single_quote(char *str, int i)
{
    int tmp;
    int j;
    char *splitted_str;

    tmp = i; //here 21
    j = 0;
    i++;
    while (str[i] != '\'')
        i++;
    splitted_str = calloc(i - tmp + 2, sizeof(char));
    //printf(" i - tmp + 1 = %d\n" , i - tmp + 1 );
    splitted_str[j] = '\'';
    j++;
    tmp++;
    while(str[tmp] != '\'')
    {
        splitted_str[j] = str[tmp];
        j++;
        tmp++;
    }
    splitted_str[j++] = '\'';
    splitted_str[j] = '\0';
    //printf("%s\n", splitted_str);
    return (splitted_str);
}

//!!!!! I need to malloc here

char    *until_single_quote(char *str, int i)
{
    int tmp;
    int j;
    char *splitted_str;

    tmp = i;
    j = 0;
    while (str[i] != '\'' && str[i] != '\0')
        i++;
    splitted_str = calloc(i - tmp + 1, sizeof(char));
    //printf(" i - tmp + 1 = %d\n" , i - tmp + 1 );
    while(str[tmp] != '\'' && str[tmp] != '\0')
    {
        splitted_str[j] = str[tmp];
        j++;
        tmp++;
    }
    splitted_str[j] = 0;
    //printf("%s\n", splitted_str);
    return (splitted_str);
}

//! le probleme est que je quitte trop vite la fonction et que j'handle pas bien l'ajout des singles quotes
//! j'oublie aussi d'ajouter un null terminator et d'alloc la memoire pour

char    **new_ft_split(char *str, char c)
{
    char **str_return;
    int i;
    int j;

    i = 0;
    j = 0;

    str_return = calloc(count_words(str) + 1, sizeof(char *));
    //printf("count of words is %d\n", count_words(str));
    if (!str_return)
        return (NULL);
    // il faut avoir une condition pour savoir comment passer au prochain mot
    while(str[i] != 0)
    {
        // ici je suis supposé mettre un mot séparé dans la double d array
        if (str[i] == c)
        {
            str_return[j] = ft_single_quote(str, i);
            i += ft_strlen(str_return[j]);
            //printf("amount of char for the word %d is %zu\n", j, ft_strlen(str_return[j]));
            //printf ("i after the word %d = %d\n", j, i);
            j++;
        }
        // ici je suis supposé continuer a mettre dans le mot actuel
        else
        {
            str_return[j] = until_single_quote(str, i);
            i += ft_strlen(str_return[j]);
            //printf("amount of char for the word %d is %zu (non single quotes)\n", j, ft_strlen(str_return[j]));
            //printf ("i after the word %d = %d (non single quotes)\n", j, i);
            j++;
        }
    }
    str_return[j] = NULL;
    return(str_return);
}

// int main() 
// {
//     char *str = "$USER$hello.    hello'$USER'  yo$USER";

//     char **words = new_ft_split(str, '\'');

//     int i = 0;
//     while (words[i] != NULL)
//     {
//         printf("Word %d: %s\n", i + 1, words[i]);
//         i++;
//     }

//     return 0;
// }

