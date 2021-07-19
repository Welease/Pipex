#include "../Libft/Libft.h"

void exit_with_message(char *message, int code) {
    write(1, message, ft_strlen(message));
    write(1, "\n", 1);
    exit(code);
}