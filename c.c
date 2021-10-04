/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarture <lbarture@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 18:34:03 by lbarture          #+#    #+#             */
/*   Updated: 2021/09/27 20:41:14 by lbarture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libftprintf.h"
#include<unistd.h>

int	print_arg(char arg)
{
	int	count;
	
	count =	write(1, arg, 1);
	return(count);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int	count;
	int	i;
	char c;

	i = 0;
	va_start(args, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			i++;
			if (str[i] == 'c')
			{
				c = va_arg(args, char);
				count = print_arg(c);
				i++;
			}
		}
		write(1, &str[i],1);
		i++;
	}

/*	while(args)
	{
		c = va_arg(args, int);
		write(1, &c,1);
	}*/
	va_end(args);
	return(i+count);
}

int	main(void)
{
	char	letra;

	letra = 'l';
	ft_printf("hola %c hello %c", letra);
}

