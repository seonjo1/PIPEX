/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonjo <seonjo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 18:20:11 by seonjo            #+#    #+#             */
/*   Updated: 2023/08/25 22:08:33 by seonjo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while (n > 0)
	{
		if (*str1 != *str2)
			return (*str1 - *str2);
		else if (!*str1 && !*str2)
			return (0);
		str1++;
		str2++;
		n--;
	}
	return (0);
}

static void	loop_find_limiter(char *limiter, int *pipe_fd)
{
	int		len;
	char	*line;

	write(1, "pipe heredoc> ", 14);
	len = ft_strlen(limiter);
	line = get_next_line(0);
	while (ft_strncmp(limiter, line, len) != 0)
	{
		ft_write(1, "pipe heredoc> ", 14);
		ft_write(pipe_fd[1], line, ft_strlen(line));
		free(line);
		line = get_next_line(0);
	}
	if (line != NULL)
		free(line);
}

void	here_doc(char *limiter, int argc)
{
	pid_t	pid;
	int		pipe_fd[2];

	if (pipe(pipe_fd) == -1)
		error(1);
	if (argc == 5)
		exit(1);
	pid = fork();
	if (pid == -1)
		error(1);
	else if (pid == 0)
	{
		ft_close(pipe_fd[0]);
		if (limiter == NULL)
			exit(0);
		limiter = ft_strjoin(limiter, "\n", 0);
		if (limiter == NULL)
			error(1);
		loop_find_limiter(limiter, pipe_fd);
		free(limiter);
		exit(0);
	}
	else
		parents_do(pid, pipe_fd);
}
