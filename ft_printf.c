#include<stdio.h>
#include"ft_printf.h"

void ft_print_u(unsigned int number)
{
	
}
int print_args(char type, va_list args)
{
    int count;
    int number;
    char    *string;

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
		ft_print_u(number);
		string = ft_itoa(number);
		return(ft_strlen(string));
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
    return(len);
}

