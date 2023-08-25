/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonjo <seonjo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 21:41:58 by seonjo            #+#    #+#             */
/*   Updated: 2023/08/25 21:45:48 by seonjo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include "ft_printf.h"
# include "get_next_line.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		parents_do(pid_t pid, int *pipe_fd);
int		ft_open(char *file, int flag);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2, int flag);
void	error(int flag);
void	ft_close(int fd);
void	move_fd(int to, int from);
void	here_doc(char *limiter, int argc);
void	exe_cmd(char *argv, int fd, char **envp);
void	ft_write(int fd, char *message, int len);
size_t	ft_strlen(const char *s);

#endif