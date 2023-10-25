/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonjo <seonjo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 18:02:49 by seonjo            #+#    #+#             */
/*   Updated: 2023/08/28 17:57:34 by seonjo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	*all_free(t_list **head, int *flag)
{
	t_list	*node;
	t_list	*tmp;

	*flag = 1;
	node = *head;
	while (node != NULL)
	{
		tmp = node -> next;
		free(node);
		node = tmp;
	}
	return (NULL);
}

void	*remove_node(t_list **head, int fd)
{
	t_list	*pre;
	t_list	*now;

	now = *head;
	if (now -> fd == fd)
	{
		*head = now -> next;
		free(now);
		return (NULL);
	}
	while (now -> fd != fd)
	{
		pre = now;
		now = pre -> next;
	}
	pre -> next = now -> next;
	free(now);
	return (NULL);
}

void	*free_dest(char *dest)
{
	free(dest);
	return (NULL);
}

t_list	*find_node(t_list **head, int fd)
{
	t_list	*node;
	t_list	*pre_node;

	node = *head;
	pre_node = NULL;
	while (node != NULL && node -> fd != fd)
	{
		pre_node = node;
		node = pre_node -> next;
	}
	if (node == NULL)
	{
		node = (t_list *)malloc(sizeof(t_list));
		if (node == NULL)
			return (NULL);
		node -> fd = fd;
		(node -> buffer)[0] = '\0';
		node -> next = NULL;
		if (pre_node == NULL)
			*head = node;
		else
			pre_node -> next = node;
	}
	return (node);
}

void	*flag_set(int *flag)
{
	*flag = 1;
	return (NULL);
}
