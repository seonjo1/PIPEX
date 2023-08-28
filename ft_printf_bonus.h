/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonjo <seonjo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 16:43:44 by seonjo            #+#    #+#             */
/*   Updated: 2023/08/28 17:59:15 by seonjo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_putnbr_16(unsigned int num, char opt, int *all_len);
int	ft_putnbr_u(unsigned int n, int *all_len);
int	ft_putnbr_d(int n, int *all_len);
int	ft_putptr(void *ptr, int *all_len);
int	ft_printf(const char *last, ...);

#endif