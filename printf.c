#include<stdarg.h>
#include<stdio.h>
#include<unistd.h>

/*int print_args(char arg)
{
    int count;

    count = 0;
    while(arg[count])
    {
        write(1, arg, 1);
        count++;
    }
    return(count);
}*/

ft_printf(const char *str, ...)
{
    // Creo la lista de argumentos, el contador, nº de posición 
    // y la variable que contendrá el char.
    va_list args;
    int count;
    int i;
    char    c;
    
    i = 0;
    // Asigno al puntero str el primer arg de la lista de args.
    va_start(args, str);
    // Mientras str no acabe pinta la posición y pasa a la siguiente.
    while(str[i] != '\0')
    {
        // Si encuentra un '%' entra y suma 1.
        if(str[i] == '%')
        {
            i++;
            // Si encuentra un caracter de char asigna a la variable de char el argumento.
            if(str[i] == 'c')
            {
                c = va_arg(args, char);
                write(1, c, 1);
               /* count = print_args(c);
                i++;*/
            }
        }
        write(1, &str[i], 1);
        i++;
    }
}

int main(void)
{
    char    letraUno;
    char    letraDos;

    letraUno = 'j';
    letraDos = 'y';
    ft_printf("hola %c hello %c", letraUno, letraDos);
}