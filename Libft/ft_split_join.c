#include "Libft.h"

static char			**free_mass(char **tab)
{
    unsigned int	i;

    i = 0;
    while (tab[i])
    {
        free(tab[i]);
        i++;
    }
    free(tab);
    return (NULL);
}

static unsigned int count_of_parts(char const *s, char c)
{
    unsigned int	i;
    unsigned int	count;

    if (!s[0])
        return (0);
    i = 0;
    count = 0;
    while (s[i] && s[i] == c)
        i++;
    while (s[i])
    {
        if (s[i] == c)
        {
            count++;
            while (s[i] && s[i] == c)
                i++;
            continue ;
        }
        i++;
    }
    if (s[i - 1] != c)
        count++;
    return (count);
}

static void			line_getting(char **line, unsigned int *ll,
                                    char c)
{
    unsigned int i;

    *line += *ll;
    *ll = 0;
    i = 0;
    while (**line && **line == c)
        (*line)++;
    while ((*line)[i])
    {
        if ((*line)[i] == c)
            return ;
        (*ll)++;
        i++;
    }
}

char				**ft_split_join(char const *s, char c, char *to_join)
{
    char			**mass;
    char			*line;
    unsigned int	ll;
    unsigned int	nb_strs;
    unsigned int	i;

    if (!s)
        return (NULL);
    nb_strs = count_of_parts(s, c);
    if (!(mass = malloc(sizeof(char *) * (nb_strs + 1))))
        return (NULL);
    i = 0;
    line = (char *)s;
    ll = 0;
    while (i < nb_strs) {
        line_getting(&line, &ll, c);
        if (!(mass[i] = malloc(sizeof(char) * (ll + 1 + ft_strlen(to_join)))))
            return (free_mass(mass));
        ft_strlcpy(mass[i], line, ll + 1);
        ft_strlcpy(mass[i] + ll, to_join, ft_strlen(to_join) + 1);
        i++;
    }
    mass[i] = NULL;
    free(to_join);
    return (mass);
}