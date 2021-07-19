cmake_minimum_required(VERSION 3.17)
project(Pipex C)

set(CMAKE_C_STANDARD 99)

add_executable(Pipex main.c Libft/Libft.h Libft/ft_strlen.c Utils/errors_handling.c Utils/Utils.h Libft/ft_split.c Libft/ft_strnstr.c Libft/ft_strdup.c Libft/ft_strjoin.c Libft/ft_split_join.c Libft/ft_strlcpy.c Libft/ft_substr.c Executing/Executing.h Executing/executing.c)