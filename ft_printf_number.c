/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_number.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonjo <seonjo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 16:42:39 by seonjo            #+#    #+#             */
/*   Updated: 2023/05/27 15:33:20 by seonjo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putnbr2(long long num, int count)
{
	char	c;

	if (num != 0)
	{
		count = ft_putnbr2(num / 10, count);
		if (count == -1)
			return (-1);
		c = num % 10 + '0';
		if (write(1, &c, 1) == -1)
			return (-1);
		count = count + 1;
	}
	return (count);
}

int	ft_putnbr_d(int n, int *all_len)
{
	long long	num;
	int			minus;
	int			count;

	num = n;
	minus = 1;
	count = 0;
	if (num == 0)
	{
		if (write(1, "0", 1) == -1)
			return (-1);
		*all_len = *all_len + 1;
	}
	if (num < 0)
	{
		if (write(1, "-", 1) == -1)
			return (-1);
		count = count + 1;
		num = -num;
	}
	count = ft_putnbr2(num, count);
	if (count == -1)
		return (-1);
	*all_len = *all_len + count;
	return (0);
}

int	ft_putnbr_u(unsigned int n, int *all_len)
{
	long long	num;
	int			minus;
	int			count;

	num = n;
	minus = 1;
	count = 0;
	if (num == 0)
	{
		if (write(1, "0", 1) == -1)
			return (-1);
		*all_len = *all_len + 1;
	}
	count = ft_putnbr2(num, count);
	if (count == -1)
		return (-1);
	*all_len = *all_len + count;
	return (0);
}

static int	ft_putnbr2_16(unsigned int num, int count, char *base)
{
	char	c;

	if (num != 0)
	{
		count = ft_putnbr2_16(num / 16, count, base);
		if (count == -1)
			return (-1);
		c = base[num % 16];
		if (write(1, &c, 1) == -1)
			return (-1);
		count = count + 1;
	}
	return (count);
}

int	ft_putnbr_16(unsigned int num, char opt, int *all_len)
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
		*all_len = *all_len + 1;
	}
	if (opt == 'X')
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	count = ft_putnbr2_16(num, count, base);
	if (count == -1)
		return (-1);
	*all_len = *all_len + count;
	return (0);
}
