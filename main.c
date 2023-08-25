/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonjo <seonjo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 15:54:02 by seonjo            #+#    #+#             */
/*   Updated: 2023/08/25 16:00:46 by seonjo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	do_pipe(char *argv, char **envp)
{
	pid_t	pid;
	int		pipe_fd[2];

	if (pipe(pipe_fd) == -1)
		error(1);
	pid = fork();
	if (pid == -1)
		error(1);
	else if (pid == 0)
	{
		ft_close(pipe_fd[0]);
		exe_cmd(argv, pipe_fd[1], envp);
		exit(0);
	}
	return (parents_do(pid, pipe_fd));
}

int	get_fd2(int argc, char **argv)
{
	int	fd2;

	if (access(argv[argc - 1], F_OK) == 0)
		if (unlink(argv[argc - 1]) == -1)
			error(1);
	fd2 = ft_open(argv[argc - 1], 2);
	return (fd2);
}

int	all_read(char *file)
{
	int		fd2;
	char	*line;

	fd2 = ft_open(file, 1);
	line = get_next_line(fd2);
	while (line != NULL)
	{
		free(line);
		line = get_next_line(fd2);
	}
	return (fd2);
}


void	last_exe(char *cmd, int fd2, int flag, char **envp)
{
	exe_cmd(cmd, fd2, envp);
	if (flag > 0)
		exit(1);
	exit(0);
}


int	main(int argc, char **argv, char **envp)
{
	int		i;
	int		fd;
	int		fd2;
	int		flag;

	i = 2;
	if (ft_strncmp(argv[1], "here_doc", 9) == 0)
	{
		if (access(argv[argc - 1], F_OK) == 0)
			fd2 = all_read(argv[argc - 1]);
		else
			fd2 = ft_open(argv[argc - 1], 2);
		i++;
		here_doc(argv[2]);
	}
	else
	{
		fd2 = ft_open(argv[argc - 1], 2);
		fd = ft_open(argv[1], 1);
		if (fd > 0)
		{
			move_fd(0, fd);
			i++;
		}
	}
	flag = 0;
	while (i < argc - 2)
		flag += do_pipe(argv[i++], envp);
	last_exe(argv[i], fd2, flag, envp);
}
