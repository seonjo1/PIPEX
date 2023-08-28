/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_cmd_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonjo <seonjo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 16:17:18 by seonjo            #+#    #+#             */
/*   Updated: 2023/08/28 17:59:49 by seonjo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

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

char	*check_cmd(char	**cmd, char **envp, int flag)
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
		path = ft_strjoin(envp_path[i++], cmd[0], 1);
		if (path == NULL)
			error(NULL, 1);
		if (access(path, X_OK | F_OK) == 0)
		{
			freeing(envp_path);
			return (path);
		}
		free(path);
	}
	if (flag == 0 && ft_printf("bash: %s: command not found\n", cmd[0]) == -1)
		error(NULL, 1);
	return (freeing(envp_path));
}

void	exe_cmd(char *argv, int fd, char **envp, int flag)
{
	char	**cmd;
	char	*path;

	cmd = ft_split(argv, ' ');
	if (cmd == NULL)
		error(NULL, 1);
	path = check_cmd(cmd, envp, flag);
	if (flag == 0)
	{
		freeing(cmd);
		if (path != NULL)
			free(path);
		return ;
	}
	if (path == NULL)
		exit(1);
	else
	{
		move_fd(1, fd);
		if (execve(path, cmd, NULL) == -1)
			error(cmd[0], 1);
	}
}

void	find_cmd(int argc, char **argv, char **envp, int i)
{
	while (i < argc - 1)
		exe_cmd(argv[i++], 0, envp, 0);
}
