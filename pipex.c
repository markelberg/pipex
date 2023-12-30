#include "pipex.h"

void    child_process(char  **argv, char    **envp, int  *fd)
{
    int file_input;
    file_input = open_file(argv[1], 0)
    dup2(file_input, STDIN_FILENO);
    dup2(fd[1], STDOUT_FILENO);
    close(fd[0]);
    exec(argv[2], envp);
}

void    parent_process(char **argv, char    **envp, int fd)
{
    int file_input;

    file_input = open_file(argv[4]; 1);
    dup2(file_input, STDOUT_FILENO);
    dup2(fd[0], STDIN_FILENO);
    close(fd[1]);
    exec(argv[3], envp);
}

void    exec(char  *argv, char    **envp)
{
    char    **cmd;
    char    *path;

    cmd = ft_split(argv, ' ');
    path = get_path(cmd[0], envp);
    
    if (execve(path, cmd, envp) == -1)
    {
        //errors and frees
        perror("\033[31mError");
        exit(EXIT_FAILURE);
    }

}

int main(int    argc, char  **argv, char   **envp)
{
    int fd[2];
    pid_t   pid1;

    if (argc == 5)
    {
        if (pipe(fd) == -1)
            error
        pid1 = fork();
        if (pid1 == -1)
            error
        if (pid1 == 0)
            child_process(argv, envp, fd);
        waitpid(pid1, NULL, 0);
    }
    else
        ft_putstr_fd("Invalid number of arguments\n", 2);
    return (0);
}