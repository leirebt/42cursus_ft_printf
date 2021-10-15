/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarture <lbarture@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 19:53:05 by lbarture          #+#    #+#             */
/*   Updated: 2021/10/15 17:20:54 by lbarture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

void	ft_print_p(uintptr_t array)
{
	char	*base16_x;

	base16_x = "0123456789abcdef";
	if (array > 15)
		ft_print_p(array / 16);
	ft_putchar_fd(base16_x[array % 16], 1);
}

int	ft_print_x(unsigned int number, char type)
{
	static int	len;
	char		*base16_x;
	char		*base16_xx;

	base16_x = "0123456789abcdef";
	base16_xx = "0123456789ABCDEF";
	if (!len)
		len = 0;
	if (number > 15)
		ft_print_x(number / 16, type);
	len++;
	if (type == 'x')
		ft_putchar_fd(base16_x[number % 16], 1);
	else if (type == 'X')
		ft_putchar_fd(base16_xx[number % 16], 1);
	return (len);
}

void	ft_print_u(unsigned int number)
{
	if (number > 9)
		ft_print_u(number / 10);
	ft_putchar_fd((number % 10) + '0', 1);
}
