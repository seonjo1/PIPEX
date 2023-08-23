/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonjo <seonjo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 18:08:01 by seonjo            #+#    #+#             */
/*   Updated: 2023/08/06 11:08:30 by seonjo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

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

char	*get_next_line(int fd);
void	*all_free(t_list **head);
void	*free_dest(char *dest);
void	*remove_node(t_list **head, int fd);
t_list	*find_node(t_list **head, int fd);

#endif