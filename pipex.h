/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonjo <seonjo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 21:41:58 by seonjo            #+#    #+#             */
/*   Updated: 2023/08/23 19:59:58 by seonjo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include "ft_printf.h"
# include "get_next_line.h"

char	**ft_split(char const *s, char c);
void	exe_cmd(char *argv);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	parents_do(pid_t pid, int *pipe_fd);
int		ft_open(char *file, int flag);
void	error(char *err_msg);
void	move_fd(int to, int from);
int		here_doc(char *limiter);
void	ft_write(int fd, char *message, int len);

#endif