#include "Libft.h"

static size_t	find_count_of_parts(char const *s, char c)
{
    size_t		i;

    i = 0;
    while (*s)
    {
        while ((*s == c) && (*s != '\0'))
            s++;
        if (*s != '\0')
            i++;
        while (*s != c && *s)
            s++;
    }
    return (i);
}

static char		**split(char const *s, char c, size_t *mass, char **res)
{
    while (*s && (mass[1] < mass[0]))
    {
        while (*s == c)
            s++;
        mass[2] = 0;
        while (s[mass[2]] != c)
            mass[2]++;
        mass[3] = -1;
        res[mass[1]] = (char*)malloc(sizeof(char) * mass[2] + 1);
        if (res == NULL)
        {
            while (mass[1] > -1)
                free(res[mass[1]--]);
            return (NULL);
        }
        while (++mass[3] < mass[2])
            res[mass[1]][mass[3]] = s[mass[3]];
        res[mass[1]++][mass[3]] = '\0';
        s = s + mass[3];
        while (*s == c)
            s++;
    }
    return (res);
}

char			**ft_split(char const *s, char c)
{
    char		**res;
    size_t		mass[4];

    if (s == NULL)
        return ((char **)ft_strdup(""));
    mass[1] = 0;
    mass[0] = find_count_of_parts(s, c);
    if (mass[0] == 0)
    {
        if ((res = malloc(8)) == NULL)
            return (NULL);
        *res = NULL;
        return (res);
    }
    if ((res = (char **)calloc(mass[0] + 1, 8)) == NULL)
        return (NULL);
    res[mass[0]] = NULL;
    if ((res = split(s, c, mass, res)) == NULL)
    {
        free(res);
        return (NULL);
    }
    return (res);
}