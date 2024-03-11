#include "expander.h"

char **all_in_one(char **final_strings,char ***triple_d_str)
{
    int i;
    int j;
    int k;

    i = 0;
    j = 0;
    k = 0;
    while (triple_d_str[i] != NULL)
    {
        j = 0;
        while(triple_d_str[i][j] != NULL)
        {
            final_strings[k] = triple_d_str[i][j];
            k++;
            j++;
        }
        // I remove because we will only have one NULL at the end of the only big double d array
        i++;
    }
    final_strings[k] = NULL;
    return(final_strings);
}

int count_number_of_words(char ***triple_d_str)
{
    int i;
    int j;
    static int total;

    i = 0;
    total = 0;
    while (triple_d_str[i] != NULL)
    {
        j = 0;
        while(triple_d_str[i][j] != NULL)
        {
            total++;
            j++;
        }
        i++;
    }
    return total; // no need to adjust after the loop
}

char **ft_split_double(char **str, char c)
{
    int i;
    int j;
    int total;
    char ***new_str_str;
    char **final_strings;

    i = 0;
    j = 0;
    (void)c;
    // ici je vais split un mot pour recevoir un string array
    // au final j'aurai le nombre inital de double d array
    while(str[i] != NULL)
        i++;
    //printf("value of i (number of words) inside of ft_split_double %d\n", i);
    new_str_str = calloc (i + 1, sizeof(char **));
    i = 0;
    while(str[i] != NULL)
    {
        // * si la premiere lettre du mot recherché est une quote on ne split pas en on
        if (str[i][0] != '\'')
            new_str_str[j] = ft_split_2(str[i], '$');
        else
        {
            new_str_str[j] = calloc(2, sizeof(char *)); 
            new_str_str[j][0] = str[i];
            new_str_str[j][1] = NULL; 
        }
        i++;
        j++;
    }
    new_str_str[j] = NULL;
    total = count_number_of_words(new_str_str);
    printf("total inside ft_split_double is %d\n", total);
    final_strings = calloc(total, sizeof(char *));
    final_strings = all_in_one(final_strings, new_str_str);

    return (final_strings);
}
