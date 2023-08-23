/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonjo <seonjo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 16:17:18 by seonjo            #+#    #+#             */
/*   Updated: 2023/08/23 20:07:18 by seonjo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	parents_do(pid_t pid, int *pipe_fd)
{
	waitpid(pid, NULL, 0);
	close(pipe_fd[1]);
	move_fd(0, pipe_fd[0]);
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

static char	*check_cmd(char	**cmd)
{
	char	*path;

	path = ft_strjoin("/bin/", cmd[0]);
	if (path == NULL)
		error("strjoin fail");
	if (access(path, X_OK | F_OK) == 0)
		return (path);
	path = ft_strjoin("/sbin/", cmd[0]);
	if (path == NULL)
		error("strjoin fail");
	if (access(path, X_OK | F_OK) == 0)
		return (path);
	path = ft_strjoin("/usr/bin/", cmd[0]);
	if (path == NULL)
		error("strjoin fail");
	if (access(path, X_OK | F_OK) == 0)
		return (path);
	path = ft_strjoin("/usr/sbin/", cmd[0]);
	if (path == NULL)
		error("strjoin fail");
	if (access(path, X_OK | F_OK) == 0)
		return (path);
	return (NULL);
}

void	exe_cmd(char *argv)
{	
	char	**cmd;

	cmd = ft_split(argv, ' ');
	if (cmd == NULL)
		error("split fail");
	cmd[0] = check_cmd(cmd);
	if (cmd[0] == NULL)
		error("invalid cmd");
	if (execve(cmd[0], cmd, NULL) == -1)
		error("execve fail");
}