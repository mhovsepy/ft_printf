/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhovsepy <mhovsepy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 19:40:09 by mhovsepy          #+#    #+#             */
/*   Updated: 2022/05/06 13:17:34 by mhovsepy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

int		ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_putnbr_base(unsigned long long a, char c);
int		ft_putnbr(long nb, int *count);
int		ft_printf(const char *str, ...);
int		ft_counstruction(const char *str, va_list ap, int i, int count);

#endif
