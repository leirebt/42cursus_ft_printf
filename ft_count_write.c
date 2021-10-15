/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_write.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarture <lbarture@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 19:49:59 by lbarture          #+#    #+#             */
/*   Updated: 2021/10/15 17:37:35 by lbarture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

int	ft_count_write_id(int number)
{
	char	*string;
	int		len;

	ft_putnbr_fd(number, 1);
	string = ft_itoa(number);
	len = ft_strlen(string);
	free(string);
	return (len);
}

int	ft_count_write_u(unsigned int number)
{
	int	len;

	len = 0;
	ft_print_u(number);
	while (number > 9)
	{
		number = number / 10;
		len++;
	}
	len++;
	return (len);
}

int	ft_count_write_x(unsigned int number, char type)
{
	int	len;

	len = 0;
	ft_print_x(number, type);
	while (number > 15)
	{
		number = number / 16;
		len++;
	}
	len++;
	return (len);
}

int	ft_count_write_p(uintptr_t number)
{
	int	len;

	len = 0;
	len = write (1, "0x", 2);
	ft_print_p(number);
	while (number > 15)
	{
		number = number / 16;
		len++;
	}
	len++;
	return (len);
}

int	ft_count_write_s(char *str)
{
	int	len;

	len = 0;
	if (!str)
		len = write (1, "(null)", 6);
	else
	{
		ft_putstr_fd(str, 1);
		len = ft_strlen(str);
	}
	return (len);
}
