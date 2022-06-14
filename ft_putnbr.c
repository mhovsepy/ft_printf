/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhovsepy <mhovsepy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 17:58:38 by mhovsepy          #+#    #+#             */
/*   Updated: 2022/05/05 15:12:48 by mhovsepy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(long nb, int *count)
{
	long	n;

	n = nb;
	if (nb < 0)
	{
		write(1, "-", 1);
		*count = *count + 1;
		n = -n;
	}
	if (n < 10)
	{
		n += 48;
		write(1, &n, 1);
		*count = *count + 1;
		return (0);
	}
	else
		ft_putnbr(n / 10, count);
	ft_putnbr(n % 10, count);
	return (*count);
}
