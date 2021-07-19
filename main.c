#include "Executing/Executing.h"

int main(int argc, char **argv, char **env) {
    if (argc != 5)
        exit_with_message("Error in input, please use program as follow: ./pipex file1 cmd1 cmd2 file2", FAIL);
    start_process(argv, env);
}
