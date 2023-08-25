/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   library.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonjo <seonjo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 18:45:56 by seonjo            #+#    #+#             */
/*   Updated: 2023/08/25 22:54:56 by seonjo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error(int flag)
{
	perror(NULL);
	if (flag == 1)
		exit(1);
}

int	ft_open(char *file, int flag)
{
	int	fd;

	if (flag == 1)
		fd = open(file, O_RDONLY);
	else if (flag == 2)
		fd = open(file, O_CREAT | O_TRUNC | O_RDWR, 0777);
	else
		fd = open(file, O_RDWR);
	if (fd < 0)
	{
		if (flag != 1 && access(file, R_OK | W_OK) == -1)
			return (-1);
		perror(NULL);
		return (-1);
	}
	return (fd);
}

void	ft_close(int fd)
{
	if (close(fd) == -1)
		error(1);
}

void	move_fd(int to, int from)
{
	ft_close(to);
	if (dup2(from, to) == -1)
		error(1);
	ft_close(from);
}

void	ft_write(int fd, char *message, int len)
{
	if (write(fd, message, len) == -1)
		error(1);
}
