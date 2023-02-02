/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbarrage <sbarrage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 14:30:15 by sbarrage          #+#    #+#             */
/*   Updated: 2022/05/27 11:53:03 by sbarrage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

# include "ft_printf.h"

int		ft_printf(const char *str, ...);
void	ft_control(char c, va_list args, int *j);
void	ft_putnbr(int n, int *j);
void	ft_putnbr_ld(unsigned int n, int *j);
void	ft_puthex(unsigned long n, char *str, int *j);
void	ft_puthex_ads(unsigned long n, char *str, int *j, int b);
void	ft_putchar(char c);
void	ft_putstr(const char *str, int *j);

#endif