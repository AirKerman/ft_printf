/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkerman <rkerman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 21:07:38 by rkerman           #+#    #+#             */
/*   Updated: 2024/11/25 15:32:28 by rkerman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	hexalen(unsigned int n, t_flags *flags)
{
	if (n == 0 && (!flags->precision
			|| (flags->precision && flags->wzero > 0)))
		flags->printzero = 1;
	else if (n == 0 && (flags->precision && flags->wzero == 0))
		flags->len--;
	if (flags->hash && n != 0)
	{
		flags->count += 2;
		if (flags->width)
			flags->width -= 2;
	}
	while (n >= 16)
	{
		n /= 16;
		flags->len++;
	}
	flags->len++;
	width_calculator(flags);
	flags->count += flags->len + flags->wzero + flags->width;
}

static void	base_hexa(unsigned int n, t_flags *flags, int len)
{
	char	*str;

	if (flags->type == 'x')
		str = "0123456789abcdef";
	else if (flags->type == 'X')
		str = "0123456789ABCDEF";
	while (flags->wzero)
	{
		write(1, "0", 1);
		flags->wzero--;
	}
	if (n >= 16)
	{
		base_hexa(n / 16, flags, len);
		base_hexa(n % 16, flags, len);
	}
	else if (n > 0 || (n == 0 && flags->printzero) || len > 1)
	{
		write(1, &str[n], 1);
	}
}

static void	display_hash(int n, t_flags flags)
{
	if (n != 0 && flags.hash)
	{
		if (flags.type == 'x')
			write(1, "0x", 2);
		else
			write(1, "0X", 2);
	}
}

void	print_x(unsigned int n, t_flags *flags)
{
	hexalen(n, flags);
	if (flags->minus)
	{
		display_hash(n, *flags);
		base_hexa(n, flags, lenint((int)n));
	}
	while (flags->width)
	{
		write(1, " ", 1);
		flags->width--;
	}
	if (!flags->minus)
	{
		display_hash(n, *flags);
		base_hexa(n, flags, lenint((int)n));
	}
}
