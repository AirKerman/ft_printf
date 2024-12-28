/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkerman <rkerman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 12:44:13 by rkerman           #+#    #+#             */
/*   Updated: 2024/11/22 21:30:06 by rkerman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	t_flags	flags;

	va_start(ap, format);
	flags.count = 0;
	while (*format)
	{
		init_flags(&flags);
		if (*format == '%' && parse_format(&ap, &flags, &format))
			display_args(ap, &flags);
		else
		{
			write(1, &*format, 1);
			flags.count++;
		}
		format++;
	}
	va_end(ap);
	return (flags.count);
}
