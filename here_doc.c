/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonjo <seonjo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 18:20:11 by seonjo            #+#    #+#             */
/*   Updated: 2023/08/31 17:57:11 by seonjo           ###   ########.fr       */
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

void	here_doc(char *limiter, int argc)
{
	pid_t	pid;
	int		pipe_fd[2];

	if (pipe(pipe_fd) == -1)
		error(NULL, 1);
	if (argc == 5)
		exit(1);
	pid = fork();
	if (pid == -1)
		error(NULL, 1);
	else if (pid == 0)
	{
		ft_close(pipe_fd[0]);
		if (limiter == NULL)
			exit(0);
	}
	else
		parents_do(pid, pipe_fd);
}
