#include "Libft.h"

char	*ft_strdup(const char *src)
{
    char	*dub;
    int		i;

    i = 0;
    while (*(src + i))
        i++;
    i++;
    dub = (char*)malloc(i);
    if (dub == NULL)
        return (NULL);
    i = 0;
    while (*(src + i))
    {
        *(dub + i) = *(src + i);
        i++;
    }
    *(dub + i) = '\0';
    return (dub);
}

