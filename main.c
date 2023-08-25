/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonjo <seonjo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 15:54:02 by seonjo            #+#    #+#             */
/*   Updated: 2023/08/25 22:56:12 by seonjo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	do_pipe(char *argv, char **envp)
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
	}
	else
		parents_do(pid, pipe_fd);
}

int	all_read(char *file)
{
	int		fd2;
	char	*line;

	fd2 = ft_open(file, 3);
	line = get_next_line(fd2);
	while (line != NULL)
	{
		free(line);
		line = get_next_line(fd2);
	}
	return (fd2);
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

void	last_exe_cmd(char *cmd, int fd2, char **envp)
{
	if (fd2 < 0)
	{
		ft_printf("Permission denied\n");
		exit(1);
	}
	exe_cmd(cmd, fd2, envp);
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
		if (access(argv[argc - 1], F_OK) == 0)
			fd2 = all_read(argv[argc - 1]);
		else
			fd2 = ft_open(argv[argc - 1], 2);
		here_doc(argv[2], argc);
		i++;
	}
	else
	{
		fd2 = ft_open(argv[argc - 1], 2);
		i += open_fd1(argv[1]);
	}
	while (i < argc - 2)
		do_pipe(argv[i++], envp);
	last_exe_cmd(argv[i], fd2, envp);
}
