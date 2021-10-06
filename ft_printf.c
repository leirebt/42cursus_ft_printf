/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarture <lbarture@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 18:53:16 by lbarture          #+#    #+#             */
/*   Updated: 2021/10/06 21:11:37 by lbarture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include"ft_printf.h"

int ft_print_p(int *array)
	// Esto no me sirve porque necsito hacer la recursiva sobre todo el array. Darle una vuelta.
	// Solo pinta la base en minúsculas.
{
	static int  len;
     char    *base16_x;
	static int	count;

     base16_x = "0123456789abcdef";
	 count = 0;
      if (!len)
          len = 0;
      if (array[count] > 9)
          ft_print_p(array[count] / 16, type);
      if(type == 'x')
         ft_putchar_fd(base16_x[array[count]] % 16], 1);
      len++;
	  count++;
      return(len);
}

int ft_print_xX(int number, char type)
{
	static int  len;
	char	*base16_x;
	char	*base16_X;

	base16_x = "0123456789abcdef";
	base16_X = "0123456789ABCDEF";
     if (!len)
         len = 0;
     if (number > 9)
         ft_print_xX(number / 16, type);
     len++;
	 if(type == 'x')
     	ft_putchar_fd(base16_x[number % 16], 1);
	 else if (type == 'X')
		 ft_putchar_fd(base16_X[number % 16], 1);
     return(len);
}

int ft_print_u(unsigned int number)
{
	static int	len;

	if (!len)
		len = 0;
	if (number > 9)
		ft_print_u(number / 10);
	len++;
	ft_putchar_fd((number % 10) + '0', 1);
	return(len);
}
int print_args(char type, va_list args)
{
    int count;
    int number;
    int    *array;

    count = 0;
    if (type == '%')
    {
        write(1,"%",1);
        return(1);
    }
    if(type == 'c')
    {
        ft_putchar_fd((va_arg(args, int)), 1);
        return(1);
    }
    if(type == 's')
    {
        string = va_arg(args, char*);
        ft_putstr_fd(string, 1);
        return(ft_strlen(string));
    }
    if(type == 'i' || type == 'd')
    {
        number = va_arg(args, int);
        ft_putnbr_fd(number, 1);
        string = ft_itoa(number);
        return(ft_strlen(string));
    }
	if(type == 'u')
	{
		number = va_arg(args, unsigned int);
		return(ft_print_u(number));
	}
	if(type == 'x' || type == 'X')
	{
		number = va_arg(args, int);
		return(ft_print_xX(number, type));
	}
	if(type == 'p')
	{
		int	count;

		count = 0;
		array = va_arg(args, int);
		return(ft_print_p(array));
	}
	return(0);
}

int ft_printf(const char *str, ...)
{
    // Creo la lista de argumentos, el contador del length y nº de posición.
    va_list args;
    int len;
    int i;
    
    i = 0;
	len = 0;
    // Asigno al puntero str el primer arg de la lista de args.
    va_start(args, str);
    // Mientras str no acabe pinta la posición y pasa a la siguiente.
    while(str[i])
    {
        // Si encuentra un '%' entra y suma 1.
        if(str[i] == '%')
        {
            // Envía el puntero y los args a imprimir.
            len = len + print_args(str[++i], args);
        } 
		else 
        	len += write(1, &str[i], 1);
		i++;
    }
	va_end(str);
    return(len);
}

