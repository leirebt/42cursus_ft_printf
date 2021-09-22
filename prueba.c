#include"libftprintf.h"

ft_printf(const char *, ...)
{
	va_list arg;

	write(1, va_start(arg, const char*), 1);

//	va_arg(arc, char);

	va_end(arg);
}

int	main(void)
{
	ft_printf("hello");
}
