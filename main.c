/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shammouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 21:51:10 by shammouc          #+#    #+#             */
/*   Updated: 2022/07/27 21:51:26 by shammouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

void	child_one(int *pipefd, int *fd, char **av, char **envp)
{
	char	**cmd;
	pid_t	c_pid;

	c_pid = fork();
	if (c_pid < 0)
		end("fork");
	if (c_pid == 0)
	{
		fd[0] = open(av[1], O_RDONLY);
		if (fd[0] < 0)
			end(av[1]);
		cmd = ft_split(av[2], ' ');
		close(pipefd[0]);
		dup2(fd[0], STDIN_FILENO);
		dup2(pipefd[1], STDOUT_FILENO);
		if (cmd[0] && ft_path(cmd[0], envp)
			&& (access(ft_path(cmd[0], envp), F_OK) != -1))
		{
			execve(ft_path(cmd[0], envp), cmd, envp);
			free_split(cmd);
		}
		else
			cmd_not_found(cmd);
	}
}

void	child_two(int *pipefd, int *fd, char **av, char **envp)
{
	char	**cmd;
	pid_t	c_pid;

	c_pid = fork();
	if (c_pid < 0)
		end("fork");
	if (c_pid == 0)
	{
		fd[1] = open(av[4], O_CREAT | O_WRONLY | O_TRUNC,
				S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
		if (fd[1] < 0)
			end(av[4]);
		cmd = ft_split(av[3], ' ');
		close(pipefd[1]);
		dup2(fd[1], STDOUT_FILENO);
		dup2(pipefd[0], STDIN_FILENO);
		if (cmd[0] && ft_path(cmd[0], envp)
			&& (access(ft_path(cmd[0], envp), F_OK) != -1))
		{
			execve(ft_path(cmd[0], envp), cmd, envp);
			free_split(cmd);
		}
		else
			cmd_not_found(cmd);
	}
}

int	not_file(char **av)
{
	int	i;

	i = 0;
	while (i < 5)
	{
		if (ft_strlen(av[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

int	main(int ac, char **av, char **envp)
{
	int	pipefd[2];
	int	fd[2];
	int	status;

	if (!envp)
		exit(EXIT_FAILURE);
	if ((ac != 5) || (not_file(av) == 0))
	{
		ft_putstr("pipex: ./pipex file1 cmd1 cmd2 file2\n", 2);
		exit(EXIT_FAILURE);
	}
	if (pipe(pipefd) < 0)
		end(NULL);
	child_one(pipefd, fd, av, envp);
	child_two(pipefd, fd, av, envp);
	close(pipefd[0]);
	close(pipefd[1]);
	waitpid(-1, &status, 0);
	waitpid(-1, &status, 0);
	return (0);
}
