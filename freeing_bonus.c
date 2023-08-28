/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonjo <seonjo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 19:24:40 by seonjo            #+#    #+#             */
/*   Updated: 2023/08/28 17:57:07 by seonjo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	*freeing(char **str)
{
	int	i;

	if (str != NULL)
	{
		i = 0;
		while (str[i] != NULL)
			free(str[i++]);
		free(str);
	}
	return (NULL);
}
