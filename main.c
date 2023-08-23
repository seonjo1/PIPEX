/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonjo <seonjo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 15:54:02 by seonjo            #+#    #+#             */
/*   Updated: 2023/08/23 19:07:21 by seonjo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// void	check_argv(int argc, char **argv)
// {
//	 ft_printf("공사 중\n");
// }

int	do_pipe(char *argv)
{
	pid_t	pid;
	int		pipe_fd[2];

	if (pipe(pipe_fd) == -1)
		error("pipe fail");
	pid = fork();
	if (pid == -1)
		error("fork fail");
	else if (pid == 0)
	{
		close(pipe_fd[0]);
		move_fd(1, pipe_fd[1]);
		exe_cmd(argv);
		return (-1);
	}
	else
		parents_do(pid, pipe_fd);
	return (pipe_fd[1]);
}

int	get_fd2(int argc, char **argv)
{
	int	fd2;

	// check_argv(argc, argv); 
	if (access(argv[argc - 1], F_OK) == 0)
		unlink(argv[argc - 1]);
	fd2 = ft_open(argv[argc - 1], 2);
	return (fd2);
}

int	all_read(int argc, char **argv)
{
	int	fd2;

	fd2 = ft_open(argv[argc - 1], 1);
	while (get_next_line(fd2) != NULL)
		;
	return (fd2);
}

void	last_exe(char *cmd, int fd, int fd2)
{
	move_fd(1, fd2);
	exe_cmd(cmd);
	while (fd >= 0)
		close(fd--);
}

int	main(int argc, char **argv)
{
	int		i;
	int		fd;
	int		fd2;

	i = 2;
	if (ft_strncmp(argv[1], "here_doc", 9) == 0)
	{
		if (access(argv[argc - 1], F_OK) == 0)
			fd2 = all_read(argc, argv);
		else
			fd2 = ft_open(argv[argc - 1], 2);
		i = here_doc(argv[2]);
	}
	else
	{
		fd2 = get_fd2(argc, argv);
		fd = ft_open(argv[1], 1);
		move_fd(0, fd);
	}
	while (i > 0 && i < argc - 2 && fd >= 0)
		fd = do_pipe(argv[i++]);
	if (i > 0 && fd >= 0)
		last_exe(argv[i], fd, fd2);
}
