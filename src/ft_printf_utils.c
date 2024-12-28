/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkerman <rkerman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 21:12:07 by rkerman           #+#    #+#             */
/*   Updated: 2024/11/22 21:53:38 by rkerman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_flags(t_flags *flags)
{
	flags->minus = 0;
	flags->zero = 0;
	flags->precision = 0;
	flags->hash = 0;
	flags->space = 0;
	flags->plus = 0;
	flags->width = 0;
	flags->wzero = 0;
	flags->len = 0;
	flags->printzero = 0;
	flags->on = 0;
	flags->type = '\0';
}

void	width_calculator(t_flags *flags)
{
	if (!flags->minus && !flags->precision && flags->width > 0 && flags->zero)
	{
		flags->precision = 1;
		if (flags->width > flags->len)
			flags->wzero = flags->width;
		else
			flags->wzero = 0;
		flags->width = 0;
	}
	if (flags->wzero > flags->len)
		flags->wzero -= flags->len;
	else
		flags->wzero = 0;
	if (flags->width > flags->len + flags->wzero)
		flags->width -= flags->len + flags->wzero;
	else
		flags->width = 0;
}

void	display_extra(int n, t_flags *flags)
{
	if (n >= 0 && (flags->plus || flags->space) && !flags->on)
	{
		if (flags->plus)
			write(1, "+", 1);
		else if (flags->space)
			write(1, " ", 1);
		flags->on = 1;
	}
	if (n < 0 && !flags->on)
		flags->on = 1;
}

int	lenint(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		n *= -1;
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

void	display_args(va_list ap, t_flags *flags)
{
	if (flags->type == 's')
		print_s(va_arg(ap, char *), flags);
	if (flags->type == 'c')
		print_c(va_arg(ap, int), flags);
	if (flags->type == '%')
		print_pe(flags);
	if (flags->type == 'd' || flags->type == 'i')
		print_di(va_arg(ap, int), flags);
	if (flags->type == 'u')
		print_u(va_arg(ap, unsigned int), flags);
	if (flags->type == 'p')
		print_p(va_arg(ap, unsigned long), flags);
	if (flags->type == 'X' || flags->type == 'x')
		print_x(va_arg(ap, unsigned int), flags);
}
