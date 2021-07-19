#include "Libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len) {
    size_t index;
    char *result_string;

    index = 0;
    if (s == NULL)
        return (NULL);
    if (start >= ft_strlen(s))
        return (result_string = ft_strdup(""));
    result_string = (char *) malloc(len + 1);
    if (result_string == NULL)
        return (NULL);
    while ((index < len))
        result_string[index++] = s[start++];
    result_string[index] = '\0';
    return (result_string);
}

