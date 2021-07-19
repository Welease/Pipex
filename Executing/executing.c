#include "Executing.h"

char **get_possible_paths(char *command, char **env) {
    int i = 0;

    char *tmp, *tmp1;
    char **res;
    if ((tmp = ft_strnstr(command, " ", ft_strlen(command)))) {
        tmp = ft_substr(command, 0, tmp - command);
    } else {
        tmp = ft_strdup(command);
    }
    tmp1 = ft_strjoin("/", tmp);
    free(tmp);
    while (env[i]) {
        if (ft_strnstr(env[i], "PATH=", 5)) {
            res = ft_split_join(env[i] + 5, ':', tmp1);
            return res;
        }
        i++;
    }
    free(tmp1);
    return NULL;
}

char		*get_path_to_exec(char *command, char **path_mass)
{
    int			i;
    struct stat buf;

    if (ft_strnstr(command, "/", ft_strlen(command)))
        return (ft_strdup(command));
    i = 0;
    if (path_mass)
        while (path_mass[i])
        {
            if (lstat(path_mass[i], &buf) < 0)
                i++;
            else if (buf.st_mode & X_OK)
                return (ft_strdup(path_mass[i]));
        }
    return (NULL);
}

void open_files(int *fds, char *file_from, char *file_to) {
    if ((fds[0] = open(file_from, O_RDONLY)) == -1)
        exit_with_message("Can't open first file", FAIL);
    if ((fds[1] = open(file_to, O_TRUNC | O_WRONLY | O_CREAT, 0777)) == -1)
        exit_with_message("Can't open second file", FAIL);
}

char **get_args_of_command(char *command) {
    return ft_split(command, ' ');
}

void exec_command(char *command, int fds[2], int pipe_fds[2], char **env, int fd) {
    char *abs_path;
    char **args;
    char **possible_paths;

    close(pipe_fds[fd]);
    dup2(fds[fd], fd);
    dup2(pipe_fds[!fd], !fd);
    close(pipe_fds[!fd]);
    possible_paths = get_possible_paths(command, env);
    if (!possible_paths || !(abs_path = get_path_to_exec(command, possible_paths)))
        exit_with_message("command not found", NOT_FOUND);
    args = get_args_of_command(command);
    if (execve(abs_path, args, env) == -1) //тут надо или нет хз но мб почистить args, abs_path, possible_paths
        exit_with_message("command not found", NOT_FOUND);
}

void start_process(char **argv, char **env) {
    pid_t pid1, pid2;
    int pipe_fds[2];
    int fds[2];
    int status1, status2;

    open_files(fds, argv[1], argv[4]);
    if (pipe(pipe_fds) == -1)
        exit_with_message("Error with pipe function", FAIL);
    if ((pid1 = fork()) < 0)
        exit_with_message("Error with fork function", FAIL);
    if (pid1 == 0)
        exec_command(argv[2], fds, pipe_fds, env, STD_IN);
    if ((pid2 = fork()) < 0)
        exit_with_message("Error with fork function", FAIL);
    if (pid2 == 0)
        exec_command(argv[3], fds, pipe_fds, env, STD_OUT);
    else {
        close(pipe_fds[STD_IN]);
        close(pipe_fds[STD_OUT]);
        waitpid(pid1, &status1, 0);
        waitpid(pid2, &status2, 0);
    }
}
