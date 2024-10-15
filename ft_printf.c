/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ereina-l <ereina-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 13:16:35 by ereina-l          #+#    #+#             */
/*   Updated: 2024/10/15 13:42:29 by ereina-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_sort(char c)
{
	if(c == c)
}
int	ft_printf(char const *str, ...)
{
	int	i;
	int	count;

	i = 0;
	count = 0;

	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
		count++;
		if (str[i] == '%')
			i++;
			ft_sort(str[i]);
			i++;
	}
}