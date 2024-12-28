/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkerman <rkerman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 19:44:17 by rkerman           #+#    #+#             */
/*   Updated: 2024/11/22 21:22:14 by rkerman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_error_s(t_flags *flags)
{
	if ((flags->precision && flags->wzero >= 6) || !flags->precision)
	{
		write(1, "(null)", 6);
		flags->count += 6;
	}
}

static void	print_error_p(t_flags *flags)
{
	if (flags->width >= 5)
		flags->width -= 5;
	else
		flags->width = 0;
	if (flags->minus)
		write(1, "(nil)", 5);
	while (flags->width)
	{
		write(1, " ", 1);
		flags->width--;
		flags->count++;
	}
	if (!flags->minus)
		write(1, "(nil)", 5);
	flags->count += 5;
}

void	display_error(t_flags *flags)
{
	if (flags->type == 's')
		print_error_s(flags);
	if (flags->type == 'p')
		print_error_p(flags);
}
