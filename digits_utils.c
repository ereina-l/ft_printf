/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   digits_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ereina-l <ereina-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 11:50:27 by ereina-l          #+#    #+#             */
/*   Updated: 2024/10/25 10:52:57 by ereina-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int n, int *count)
{
	if (n == -2147483648)
	{
		*count += write(1, "-2147483648", 11);
	}
	else if (n < 0)
	{
		*count += write(1, "-", 1);
		n = -(n);
		ft_putnbr(n, count);
	}
	else if (n > 9)
	{
		ft_putnbr(n / 10, count);
		ft_putnbr(n % 10, count);
	}
	else
	{
		n = n + '0';
		*count += write(1, &n, 1);
	}
}

void	ft_putunsigned(unsigned int n, int *count)
{
	if (n > 9)
	{
		ft_putunsigned(n / 10, count);
		ft_putunsigned(n % 10, count);
	}
	else
	{
		n = n + '0';
		*count += write(1, &n, 1);
	}
}

void	ft_puthex(unsigned long long n, int *count, bool caps)
{
	int	convert;

	if (caps)
		convert = 55;
	else
		convert = 87;
	if (n > 15)
	{
		ft_puthex(n / 16, count, caps);
		ft_puthex(n % 16, count, caps);
	}
	else
	{
		if (n < 10)
			n = n + '0';
		else
			n += convert;
		*count += write(1, &n, 1);
	}
}

void	ft_putptr(unsigned long long ptr, int *count)
{
	if (ptr == 0)
	{
		*count += ft_print_str("(nil)");
	}
	else
	{
		*count += ft_print_str("0x");
		ft_puthex(ptr, count, false);
	}
}
