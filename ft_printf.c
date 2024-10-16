/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ereina-l <ereina-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 13:16:35 by ereina-l          #+#    #+#             */
/*   Updated: 2024/10/16 12:52:05 by ereina-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_sort(char c, va_list lst, int *count)
{
	if (c == 'c')
		*count += ft_print_char(va_arg(lst, int));
	else if (c == 's')
		*count += ft_print_str(va_arg(lst, char *));
}
int	ft_printf(char const *str, ...)
{
	int	i;
	int	count;
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
#include <stdio.h>
int	main(void)
{
	int	ret;
	
	ret = ft_printf("dig: %c\nstr: %s\n", 'p', "me");
	printf("el valor de retorno es: %d\n", ret);
	return (0);
}