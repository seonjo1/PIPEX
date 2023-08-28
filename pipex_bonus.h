/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonjo <seonjo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 21:41:58 by seonjo            #+#    #+#             */
/*   Updated: 2023/08/28 17:58:40 by seonjo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include "ft_printf_bonus.h"
# include "get_next_line_bonus.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		parents_do(pid_t pid, int *pipe_fd);
int		ft_open(char *file, int flag);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2, int flag);
void	error(char *meg, int flag);
void	ft_close(int fd);
void	move_fd(int to, int from);
void	here_doc(char *limiter, int argc);
void	exe_cmd(char *argv, int fd, char **envp, int flag);
void	ft_write(int fd, char *message, int len);
void	find_cmd(int argc, char **argv, char **envp, int i);
void	*freeing(char **str);
size_t	ft_strlen(const char *s);

#endif