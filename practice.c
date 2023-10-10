#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int	ft_error(char *str)
{
	while (*str)
		write(2, str++, 1);
	return (1);
}
int	cd(char **argv, int i)
{
	if (i != 2)
		return (ft_error("error: bad argument\n"));
	else if (chdir(argv[1]) == -1)
		return (ft_error("error\n"));
	return (0);
}
int	exec(char **argv, char **envp, int i)
{
	int	fd[2];
	int	status;
	int	has_pipe;

	has_pipe = (argv[i] && !strcmp(argv[i], "|"));
	if (has_pipe && pipe(fd) == -1)
		return (ft_error("error: fatal"));
	int pid = fork(); //
	if (!pid)
	{
		argv[i] = 0;
		if (has_pipe && (dup2(fd[1], 1) == -1 || close(fd[0]) == -1
				|| close(fd[1]) == -1))
			return (ft_error("error: fatal"));
		execve(*argv, argv, envp);
		return (ft_error(""));
	}
	waitpid(pid, &status, 0);
	if (has_pipe && (dup2(fd[0], 0) == -1 || close(fd[0]) == -1
			|| close(fd[1]) == -1))
		return (ft_error("error: fatal"));
	return (WIFEXITED(status), WEXITSTATUS(status));
}

int	main(int argc, char **argv, char **envp)
{
	int	status;
	int	i;

	status = 0;
	i = 0;
	if (argc > 1)
	{
		while (argv[i] && argv[++i])
		{
			argv += i;
			i = 0;
			while (argv[i] && strcmp(argv[i], "|") && strcmp(argv[i], ";"))
				i++;
			if (!strcmp(*argv, "cd"))
				status = cd(argv, i);
			else if (i)
				status = exec(argv, envp, i);
		}
	}
	return (status);
}