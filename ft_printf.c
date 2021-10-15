/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarture <lbarture@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 19:55:48 by lbarture          #+#    #+#             */
/*   Updated: 2021/10/15 17:37:46 by lbarture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

int	print_args(char type, va_list args)
{
	int	len;

	if (type == '%')
		len = write (1, "%", 1);
	if (type == 'c')
	{
		ft_putchar_fd((va_arg(args, int)), 1);
		return (1);
	}
	if (type == 's')
		len = ft_count_write_s(va_arg(args, char *));
	if (type == 'i' || type == 'd')
		len = ft_count_write_id(va_arg(args, int));
	if (type == 'u')
		len = ft_count_write_u(va_arg(args, unsigned int));
	if (type == 'x' || type == 'X')
		len = ft_count_write_x(va_arg(args, unsigned int), type);
	if (type == 'p')
		len = ft_count_write_p(va_arg(args, uintptr_t));
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		len;
	int		i;

	i = 0;
	len = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
			len = len + print_args(str[++i], args);
		else
			len += write(1, &str[i], 1);
		i++;
	}
	va_end(args);
	return (len);
}
