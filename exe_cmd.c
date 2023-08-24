/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonjo <seonjo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 16:17:18 by seonjo            #+#    #+#             */
/*   Updated: 2023/08/24 17:32:04 by seonjo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	parents_do(pid_t pid, int *pipe_fd)
{
	int	status;

	status = 0;
	waitpid(pid, &status, 0);
	if (status == 1)
		exit(1);
	ft_close(pipe_fd[1]);
	move_fd(0, pipe_fd[0]);
	return (status);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (str == 0)
		return (0);
	while (s1[j])
		str[i++] = s1[j++];
	j = 0;
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = 0;
	return (str);
}

char	*check_cmd(char	**cmd)
{
	char	*path;

	path = ft_strjoin("/bin/", cmd[0]);
	if (path == NULL)
		error("strjoin fail", 1);
	if (access(path, X_OK | F_OK) == 0)
		return (path);
	path = ft_strjoin("/sbin/", cmd[0]);
	if (path == NULL)
		error("strjoin fail", 1);
	if (access(path, X_OK | F_OK) == 0)
		return (path);
	path = ft_strjoin("/usr/bin/", cmd[0]);
	if (path == NULL)
		error("strjoin fail", 1);
	if (access(path, X_OK | F_OK) == 0)
		return (path);
	path = ft_strjoin("/usr/sbin/", cmd[0]);
	if (path == NULL)
		error("strjoin fail", 1);
	if (access(path, X_OK | F_OK) == 0)
		return (path);
	ft_printf("zsh: command not found: %s\n", cmd[0]);
	return (NULL);
}

void	exe_cmd(char *argv, int fd)
{	
	char	**cmd;

	cmd = ft_split(argv, ' ');
	if (cmd == NULL)
		error("split fail", 1);
	cmd[0] = check_cmd(cmd);
	if (cmd[0] == NULL)
		exit(1);
	else
	{
		move_fd(1, fd);
		if (execve(cmd[0], cmd, NULL) == -1)
			exit(1);
	}
}
