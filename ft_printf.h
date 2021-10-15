/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarture <lbarture@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 17:35:26 by lbarture          #+#    #+#             */
/*   Updated: 2021/10/15 17:36:50 by lbarture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *str, ...);
int		print_args(char type, va_list args);
int		ft_count_write_s(char *str);
int		ft_count_write_p(uintptr_t number);
int		ft_count_write_x(unsigned int number, char type);
int		ft_count_write_u(unsigned int number);
int		ft_count_write_id(int number);
void	ft_print_u(unsigned int number);
int		ft_print_x(unsigned int number, char type);
void	ft_print_p(uintptr_t array);

#endif
