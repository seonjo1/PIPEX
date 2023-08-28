/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonjo <seonjo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 18:08:01 by seonjo            #+#    #+#             */
/*   Updated: 2023/08/28 18:05:43 by seonjo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000000
# endif

typedef struct s_list
{
	int				fd;
	char			buffer[BUFFER_SIZE + 1];
	struct s_list	*next;
}t_list;

char	*get_next_line(int fd, int *flag);
void	*all_free(t_list **head, int *flag);
void	*free_dest(char *dest);
void	*flag_set(int *flag);
void	*remove_node(t_list **head, int fd);
t_list	*find_node(t_list **head, int fd);

#endif