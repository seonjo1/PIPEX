/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonjo <seonjo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 16:17:18 by seonjo            #+#    #+#             */
/*   Updated: 2023/08/25 20:53:24 by seonjo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	parents_do(pid_t pid, int *pipe_fd)
{
	ft_close(pipe_fd[1]);
	waitpid(pid, NULL, 0);
	move_fd(0, pipe_fd[0]);
	return (1);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2, int flag)
{
	char	*str;
	size_t	i;
	size_t	j;
	size_t	len1;

	i = 0;
	j = 0;
	len1 = ft_strlen(s1) + flag;
	str = (char *)malloc(sizeof(char) * (len1 + ft_strlen(s2) + 1));
	if (str == 0)
		return (0);
	while (s1[j])
		str[i++] = s1[j++];
	if (flag == 1)
		str[i++] = '/';
	j = 0;
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = 0;
	return (str);
}

char	*check_cmd(char	**cmd, char **envp)
{
	int		i;
	char	**envp_path;
	char	*path;

	i = 0;
	while (ft_strncmp("PATH=", envp[i], 5) != 0)
		i++;
	envp_path = ft_split(envp[i] + 5, ':');
	i = 0;
	while (envp_path[i] != NULL)
	{
		path = ft_strjoin(envp_path[i], cmd[0], 1);
		if (path == NULL)
			error(1);
		if (access(path, X_OK | F_OK) == 0)
			return (path);
		i++;
	}
	ft_printf("command not found: %s\n", cmd[0]);
	return (NULL);
}

void	exe_cmd(char *argv, int fd, char **envp)
{	
	char	**cmd;

	cmd = ft_split(argv, ' ');
	if (cmd == NULL)
		error(1);
	cmd[0] = check_cmd(cmd, envp);
	if (cmd[0] == NULL)
		exit(1);
	else
	{
		move_fd(1, fd);
		if (execve(cmd[0], cmd, NULL) == -1)
			exit(1);
	}
}
