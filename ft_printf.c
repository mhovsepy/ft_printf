/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhovsepy <mhovsepy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 19:40:04 by mhovsepy          #+#    #+#             */
/*   Updated: 2022/05/06 13:33:59 by mhovsepy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_counstruction(const char *str, va_list ap, int i, int count)
{
	if (str[i] == 'c')
		count += ft_putchar(va_arg(ap, int));
	else if (str[i] == 's')
		count += ft_putstr(va_arg(ap, char *));
	else if (str[i] == 'p')
	{
		write(1, "0x", 2);
		count += ft_putnbr_base(va_arg(ap, unsigned long int), 'x') + 2;
	}
	else if (str[i] == 'x')
		count += ft_putnbr_base(va_arg(ap, unsigned int), 'x');
	else if (str[i] == 'X')
		count += ft_putnbr_base(va_arg(ap, unsigned int), 'X');
	else if (str[i] == 'd' || str[i] == 'i')
		ft_putnbr(va_arg(ap, int), &count);
	else if (str[i] == 'u')
		ft_putnbr(va_arg(ap, unsigned int), &count);
	else if (str[i] == '%')
	{
		write(1, "%", 1);
		count += 1;
	}
	return (count);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	ap;
	int		count;

	count = 0;
	va_start(ap, str);
	i = -1;
	while (str && str[++i])
	{
		if (str[i] == '%' && ++i)
			count += ft_counstruction(str, ap, i, 0);
		else
			count += ft_putchar(str[i]);
	}
	va_end(ap);
	return (count);
}
