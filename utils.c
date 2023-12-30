#include "pipex.h"

int open_file(char  *file, int  fd)
{
    int aux;

    if (fd == -1)
        exit(0);
    if (fd == 0)
        aux = open(file, O_RDONLY, 0777);
    if (fd == 1)
        aux = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0777);
    return (aux);
}

char    *get_path(char   *cmd, char  **envp)
{
    char    **path_split;
    char    *path_join;
    char    *full_path;
    int     i;

    i = 0;
    while (ft_strnstr(envp[i], "PATH", 4) == 0)
        i++;
    path_split = ft_split(envp[i] + 5, ':');
    i = 0;
    while (path_split[i])
    {
        path_join = ft_strjoin(path_split[i], '/');
        full_path = ft_strjoin(path_split[i], cmd);
        free(path_join);
        if (access(full_path, F_OK) == 0)
            return (full_path);
        free(full_path);
        i++;
    }
    i = 0;
    while (path_split[i])
    {
        free(path_split[i]);
        i++;
    }
    return (0);
}