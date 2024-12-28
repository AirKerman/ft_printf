/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkerman <rkerman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 20:57:46 by rkerman           #+#    #+#             */
/*   Updated: 2024/11/22 21:43:56 by rkerman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	unslen(t_flags *flags, unsigned int number)
{
	if (number == 0 && (!flags->precision
			|| (flags->precision && flags->wzero > 0)))
	{
		flags->len++;
		flags->printzero = 1;
	}
	while (number)
	{
		number /= 10;
		flags->len++;
	}
	width_calculator(flags);
	flags->count += flags->len + flags->wzero + flags->width;
}

static void	printf_putnbru(unsigned int n, t_flags flags, int len)
{
	while (flags.wzero)
	{
		write (1, "0", 1);
		flags.wzero--;
	}
	if (n > 9)
	{
		printf_putnbru(n / 10, flags, len);
		printf_putnbru(n % 10, flags, len);
	}
	else if (n > 0 || (n == 0 && flags.printzero) || (n == 0 && len > 1))
	{
		n += 48;
		write(1, &n, 1);
	}
}

void	print_u(unsigned int n, t_flags *flags)
{
	unslen(flags, n);
	if (flags->minus)
		printf_putnbru(n, *flags, lenint(n));
	while (flags->width)
	{
		write(1, " ", 1);
		flags->width--;
	}
	if (!flags->minus)
		printf_putnbru(n, *flags, lenint(n));
}
