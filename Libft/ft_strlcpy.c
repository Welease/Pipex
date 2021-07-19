#include "Libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
    size_t	i;

    i = 0;
    if (src == NULL)
        return (0);
    if (dstsize == 0 || dst == NULL)
        return (ft_strlen(src));
    while (i < (dstsize - 1))
    {
        *(dst + i) = *(src + i);
        if (*(src + i) == '\0')
            return (ft_strlen(src));
        i++;
    }
    *(dst + i) = '\0';
    return (ft_strlen(src));
}
