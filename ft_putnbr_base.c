/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhovsepy <mhovsepy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 13:43:56 by mhovsepy          #+#    #+#             */
/*   Updated: 2022/05/09 17:18:06 by mhovsepy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base(unsigned long long a, char c)
{
	char	d[100];
	int		i;
	int		byte;
	char	*base;

	base = "0123456789abcdef";
	i = 0;
	if (a == 0 && ++i)
		d[0] = '0';
	if (c == 'X')
		base = "0123456789ABCDEF";
	byte = 0;
	while (a != 0)
	{
		d[i++] = base[a % 16];
		a = a / 16;
	}
	byte = i;
	while (i != 0)
		ft_putchar(d[--i]);
	return (byte);
}
