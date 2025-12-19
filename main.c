#include "ft_pipex.h"

void	redirect_stdinout(int f, char *file_path)
{
	int	mask;

	mask = O_RDWR;
	if (f)
		mask = O_RDWR | O_TRUNC | O_CREAT;
	if (close(f) == -1)
	{
		perror(NULL);
		exit(-1);
	}
	if (open(file_path, mask, 0640) == -1)
	{
		perror(file_path);
		exit(-1);
	}
}

void	redirect_pipe(int *p, int pend)
{
	if (dup2(p[pend], pend) == -1)
	{
		perror(NULL);
		exit(-1);
	}
	if (close(p[0]) == -1)
	{
		perror(NULL);
		exit(-1);
	}
	if (close(p[1]) == -1)
	{
		perror(NULL);
		exit(-1);
	}
}

void	handle_child(char *argv_s, char *file_path, int *p, int f, char **envp)
{
	char	**argv_sub;
	char	*full_path;
	int		pend;

	pend = 1;
	if (f)
		pend = 0;
	redirect_stdinout(f, file_path);
	redirect_pipe(p, pend);
	argv_sub = ft_strsplit(argv_s, ' ');
	full_path = get_bin_fullpath(argv_sub[0], envp);
	if (execve(full_path, argv_sub, NULL) == -1)
	{
		perror(NULL);
		exit(-1);
	}
}

int	main(int argc, char **argv, char **envp)
{
	int p[2];

	if (argc == 5)
	{
		pipe(p);
		if (fork() == 0)
		{
			handle_child(argv[CMD1], argv[FILE1], p, 0, envp);
		}
		else if (fork() == 0)
		{
			handle_child(argv[CMD2], argv[FILE2], p, 1, envp);
		}
		exit(0);
	}
	else
	{
		ft_printf("Not enough args: ./pipex file1 cmd1 cmd2 file2\n");
		exit(-1);
	}
}
