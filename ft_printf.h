/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonjo <seonjo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 16:43:44 by seonjo            #+#    #+#             */
/*   Updated: 2023/04/01 17:39:32 by seonjo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_putnbr_16(unsigned int num, char opt, int *all_len);
int	ft_putnbr_u(unsigned int n, int *all_len);
int	ft_putnbr_d(int n, int *all_len);
int	ft_putptr(void *ptr, int *all_len);
int	ft_printf(const char *last, ...);

#endif