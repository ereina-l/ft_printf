/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ereina-l <ereina-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 12:58:00 by ereina-l          #+#    #+#             */
/*   Updated: 2024/10/19 12:26:49 by ereina-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdbool.h>

int		ft_print_char(int c);
int		ft_print_str(char *str);
void	ft_putnbr(int n, int *count);
void	ft_puthex(unsigned long long n, int *count, bool caps);
void	ft_putptr(unsigned long long ptr, int *count);
void	ft_putunsigned(unsigned int n, int *count);
int		ft_printf(char const *str, ...);

#endif