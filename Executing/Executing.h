#ifndef PIPEX_EXECUTING_H
#define PIPEX_EXECUTING_H

#include <stdio.h>
#include <fcntl.h>
#include <ftw.h>
#include <wait.h>
#include "../Libft/Libft.h"
#include "../Utils/Utils.h"

void start_process(char **argv, char **env);

#endif //PIPEX_EXECUTING_H
