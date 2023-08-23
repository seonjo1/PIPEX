/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   library.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonjo <seonjo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 18:45:56 by seonjo            #+#    #+#             */
/*   Updated: 2023/08/23 18:56:10 by seonjo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error(char *err_msg)
{
	perror(err_msg);
	exit(1);
}

int	ft_open(char *file, int flag)
{
	int	fd;

	if (flag == 1)
		fd = open(file, O_RDWR);
	else
		fd = open(file, O_CREAT | O_RDWR, 0777);
	if (fd < 0)
		error("open fail");
	return (fd);
}

void	move_fd(int to, int from)
{
	close(to);
	dup2(from, to);
	close(from);
}
