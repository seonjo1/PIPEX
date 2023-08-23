/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pointer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonjo <seonjo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 22:20:41 by seonjo            #+#    #+#             */
/*   Updated: 2023/05/27 15:20:48 by seonjo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putptr3(size_t num, int count, char *base)
{
	char	c;

	if (num != 0)
	{
		count = ft_putptr3(num / 16, count, base);
		if (count == -1)
			return (-1);
		c = base[num % 16];
		if (write(1, &c, 1) == -1)
			return (-1);
		count = count + 1;
	}
	return (count);
}

static int	ft_putptr2(size_t num, char opt)
{
	int		minus;
	int		count;
	char	*base;

	minus = 1;
	count = 0;
	if (num == 0)
	{
		if (write(1, "0", 1) == -1)
			return (-1);
		return (1);
	}
	else
	{
		if (opt == 'X')
			base = "0123456789ABCDEF";
		else
			base = "0123456789abcdef";
		count = ft_putptr3(num, count, base);
	}
	if (count == -1)
		return (-1);
	else
		return (count);
}

int	ft_putptr(void *ptr, int *all_len)
{
	size_t	p;
	int		len;

	if (write(1, "0x", 2) == -1)
		return (-1);
	p = (size_t)ptr;
	len = ft_putptr2(p, 'x');
	if (len == -1)
		return (-1);
	*all_len = *all_len + len + 2;
	return (0);
}
