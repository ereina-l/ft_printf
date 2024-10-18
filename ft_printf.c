/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ereina-l <ereina-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 13:16:35 by ereina-l          #+#    #+#             */
/*   Updated: 2024/10/18 17:00:37 by ereina-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_sort(char c, va_list lst, int *count)
{
	if (c == 'c')
		*count += ft_print_char(va_arg(lst, int));
	else if (c == 's')
		*count += ft_print_str(va_arg(lst, char *));
	else if (c == 'i' || c == 'd')
		ft_putnbr(va_arg(lst, int), count);
	else if (c == 'x')
		ft_puthex(va_arg(lst, unsigned int), count, false);
	else if (c == 'X')
		ft_puthex(va_arg(lst, unsigned int), count, true);
	else if (c == 'p')
		ft_putptr(va_arg(lst, unsigned long long), count);
	else if (c == '%')
		*count += ft_print_char(c);
}

int	ft_printf(char const *str, ...)
{
	int		i;
	int		count;
	va_list	lst;

	i = 0;
	count = 0;
	va_start(lst, str);
	while (str[i])
	{
		if (str[i] != '%')
		{
			count += ft_print_char(str[i]);
		}
		else
		{
			i++;
			ft_sort(str[i], lst, &count);
		}
		i++;
	}
	va_end(lst);
	return (count);
}
/* #include <stdio.h>

int	main(void)
{
	int	ret;
	int rettr;
	int ptr = 42;

	ret = ft_printf("lower: %x\nupper: \
	 %X\n pointer: %p\n percent: %%", 1234, 1234, &ptr);
	printf("el valor de retorno es: %d\n", ret);
	rettr = printf("lower: %x\nupper: \
	%X\n pointer: %p\n percent: %%", 1234, 1234, &ptr);
	printf("el valor de retorno es: %d\n", rettr);
	return (0);
} */