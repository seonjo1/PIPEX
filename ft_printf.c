/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonjo <seonjo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 14:54:37 by seonjo            #+#    #+#             */
/*   Updated: 2023/08/22 21:57:48 by seonjo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putstr(char *s, int *all_len)
{
	int	i;

	if (s == NULL)
	{
		if (write(1, "(null)", 6) == -1)
			return (-1);
		*all_len = *all_len + 6;
	}
	else
	{
		i = 0;
		while (s[i] != '\0')
		{
			if (write(1, &s[i], 1) == -1)
				return (-1);
			i = i + 1;
		}
		*all_len = *all_len + i;
	}
	return (0);
}

static int	ft_putchar(char c, int *all_len)
{
	if (write(1, &c, 1) == -1)
		return (-1);
	*all_len = *all_len + 1;
	return (0);
}

static int	ft_printf2(char c, va_list *ap, int *all_len)
{
	int	error_flag;

	error_flag = -1;
	if (c == 'c')
		error_flag = ft_putchar((char)va_arg(*ap, int), all_len);
	else if (c == 's')
		error_flag = ft_putstr(va_arg(*ap, char *), all_len);
	else if (c == 'p')
		error_flag = ft_putptr(va_arg(*ap, void *), all_len);
	else if (c == 'd' || c == 'i')
		error_flag = ft_putnbr_d(va_arg(*ap, int), all_len);
	else if (c == 'u')
		error_flag = ft_putnbr_u(va_arg(*ap, unsigned int), all_len);
	else if (c == 'x')
		error_flag = ft_putnbr_16(va_arg(*ap, unsigned int), 'x', all_len);
	else if (c == 'X')
		error_flag = ft_putnbr_16(va_arg(*ap, unsigned int), 'X', all_len);
	else if (c == '%')
		error_flag = ft_putchar('%', all_len);
	if (error_flag == -1)
		return (-1);
	else
		return (0);
}

int	ft_printf(const char *last, ...)
{
	va_list	ap;
	size_t	i;
	int		all_len;

	va_start(ap, last);
	all_len = 0;
	i = 0;
	while (last[i] != '\0')
	{
		if (last[i++] == '%')
		{
			if (last[i] == '\0')
				return (-1);
			if (ft_printf2(last[i++], &ap, &all_len) == -1)
				return (-1);
		}
		else if (ft_putchar(last[i - 1], &all_len) == -1)
			return (-1);
	}
	va_end(ap);
	return (all_len);
}
