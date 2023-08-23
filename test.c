#include "pipex.h"
#include <stdio.h>

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
	if (access(path, X_OK | F_OK) == 0)
		return (path);
	path = ft_strjoin("/sbin/", cmd[0]);
	if (access(path, X_OK | F_OK) == 0)
		return (path);
	path = ft_strjoin("/usr/bin/", cmd[0]);
	if (access(path, X_OK | F_OK) == 0)
		return (path);
	path = ft_strjoin("/usr/sbin/", cmd[0]);
	if (access(path, X_OK | F_OK) == 0)
		return (path);
	return (NULL);
}

void	exe_cmd(char *argv)
{	
	char	**cmd;

	cmd = ft_split(argv, ' ');
	cmd[0] = check_cmd(cmd);
	// if (cmd[0] == NULL)
	// 	ft_printf("invalid cmd\n");
	execve(cmd[0], cmd, NULL);
}
int main(int argc, char **argv)
{
	int fd = open("text", O_RDWR);
	close(argc - argc);
	if (dup2(fd, 0) == -1)
		exit(0);
	exe_cmd(argv[1]);
}