/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   library.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonjo <seonjo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 18:45:56 by seonjo            #+#    #+#             */
/*   Updated: 2023/08/24 19:28:43 by seonjo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error(char *err_msg, int flag)
{
	perror(err_msg);
	if (flag == 1)
		exit(1);
}

int	ft_open(char *file, int flag)
{
	int	fd;

	if (flag == 1)
		fd = open(file, O_RDWR);
	else
		fd = open(file, O_CREAT | O_TRUNC | O_RDWR, 0777);
	if (fd < 0)
		error("open fail", 1);
	return (fd);
}

void	ft_close(int fd)
{
	if (close(fd) == -1)
		error("close fail", 1);
}

void	move_fd(int to, int from)
{
	ft_close(to);
	if (dup2(from, to) == -1)
		error("dup fail", 1);
	ft_close(from);
}

void	ft_write(int fd, char *message, int len)
{
	if (write(fd, message, len) == -1)
		error("write fail", 1);
}
