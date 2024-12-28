/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkerman <rkerman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 20:15:16 by rkerman           #+#    #+#             */
/*   Updated: 2024/11/22 21:28:28 by rkerman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	convert_negativ(int *n)
{
	if (*n < 0)
	{
		*n *= -1;
		write(1, "-", 1);
	}
}

static void	print_min(int zero)
{
	write(1, "-", 1);
	while (zero--)
	{
		write (1, "0", 1);
	}
	write(1, "2147483648", 10);
}

static void	intlen(int number, t_flags *flags)
{
	if (number == 0 && (!flags->precision
			|| (flags->precision && flags->wzero > 0)))
	{
		flags->len++;
		flags->printzero = 1;
	}
	if (number < 0 || flags->plus || flags->space)
	{
		if (number < 0)
			number *= -1;
		flags->count++;
		if (flags->width)
			flags->width--;
	}
	while (number)
	{
		number /= 10;
		flags->len++;
	}
	width_calculator(flags);
	flags->count += flags->len + flags->wzero + flags->width;
}

static void	printf_putnbr(int n, t_flags flags, int len)
{
	if (n > 2147483647)
		n += -2147483648;
	if (n == -2147483648)
	{
		print_min(flags.wzero);
		return ;
	}
	display_extra(n, &flags);
	convert_negativ(&n);
	while (flags.wzero)
	{
		write (1, "0", 1);
		flags.wzero--;
	}
	if (n > 9)
	{
		printf_putnbr(n / 10, flags, len);
		printf_putnbr(n % 10, flags, len);
	}
	else if (n > 0 || (n == 0 && flags.printzero) || (n == 0 && len > 1))
	{
		n += 48;
		write(1, &n, 1);
	}
}

void	print_di(int n, t_flags *flags)
{
	intlen(n, flags);
	if (flags->minus)
		printf_putnbr(n, *flags, lenint(n));
	while (flags->width)
	{
		write(1, " ", 1);
		flags->width--;
	}
	if (!flags->minus)
		printf_putnbr(n, *flags, lenint(n));
}
