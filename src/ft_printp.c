/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkerman <rkerman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 20:49:40 by rkerman           #+#    #+#             */
/*   Updated: 2024/11/22 21:41:35 by rkerman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	base_hex(unsigned long p, t_flags *flags)
{
	char	*str;

	str = "0123456789abcdef";
	display_extra(1, flags);
	while (flags->wzero)
	{
		write(1, "0", 1);
		flags->wzero--;
	}
	if (p >= 16)
	{
		base_hex(p / 16, flags);
		base_hex(p % 16, flags);
	}
	else
	{
		write(1, &str[p], 1);
	}
}

static void	poilen(unsigned long p, t_flags *flags)
{
	if (flags->plus || flags->space)
	{
		flags->count++;
		if (flags->width)
			flags->width--;
	}
	while (p >= 16)
	{
		p /= 16;
		flags->len++;
	}
	flags->len += 3;
	width_calculator(flags);
	flags->count += flags->len + flags->wzero + flags->width;
}

void	print_p(unsigned long p, t_flags *flags)
{
	if (!p)
	{
		display_error(flags);
		return ;
	}
	poilen(p, flags);
	if (flags->minus)
	{
		write (1, "0x", 2);
		base_hex(p, flags);
	}
	while (flags->width)
	{
		write(1, " ", 1);
		flags->width--;
	}
	if (!flags->minus)
	{
		write (1, "0x", 2);
		base_hex(p, flags);
	}
}
