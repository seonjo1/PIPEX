/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonjo <seonjo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 15:54:02 by seonjo            #+#    #+#             */
/*   Updated: 2023/08/28 17:58:02 by seonjo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	do_pipe(char *argv, char **envp)
{
	pid_t	pid;
	int		pipe_fd[2];

	if (pipe(pipe_fd) == -1)
		error(NULL, 1);
	pid = fork();
	if (pid == -1)
		error(NULL, 1);
	else if (pid == 0)
	{
		ft_close(pipe_fd[0]);
		exe_cmd(argv, pipe_fd[1], envp, 1);
	}
	else
		parents_do(pid, pipe_fd);
}

int	parents_do(pid_t pid, int *pipe_fd)
{
	ft_close(pipe_fd[1]);
	waitpid(pid, NULL, 0);
	move_fd(0, pipe_fd[0]);
	return (1);
}

int	open_fd1(char *file1)
{	
	int	fd;

	fd = ft_open(file1, 1);
	if (fd == -1)
	{
		here_doc(NULL, 1);
		return (1);
	}
	else
		move_fd(0, fd);
	return (0);
}

int	open_fd2(char *file2, int flag)
{
	int	fd2;

	if (flag == 0)
	{
		if (access(file2, F_OK) == 0)
			fd2 = ft_open(file2, 3);
		else
			fd2 = ft_open(file2, 2);
	}
	else
		fd2 = ft_open(file2, 2);
	return (fd2);
}

int	main(int argc, char **argv, char **envp)
{
	int		i;
	int		fd2;

	i = 2;
	if (argc < 5)
		exit(1);
	else if (ft_strncmp(argv[1], "here_doc", 9) == 0)
	{
		here_doc(argv[2], argc);
		i++;
		fd2 = open_fd2(argv[argc - 1], 0);
		find_cmd(argc, argv, envp, i);
	}
	else
	{
		i += open_fd1(argv[1]);
		fd2 = open_fd2(argv[argc - 1], 1);
		find_cmd(argc, argv, envp, i);
	}
	while (i < argc - 2)
		do_pipe(argv[i++], envp);
	if (fd2 == -1)
		exit(1);
	exe_cmd(argv[i], fd2, envp, 1);
}
