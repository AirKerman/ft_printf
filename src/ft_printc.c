/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkerman <rkerman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 19:58:52 by rkerman           #+#    #+#             */
/*   Updated: 2024/11/22 21:38:54 by rkerman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_c(int c, t_flags *flags)
{
	if (c >= 256)
		c %= 256;
	if (flags->minus)
	{
		write (1, &c, 1);
		flags->count++;
	}
	while (flags->width > 1 && flags->width--)
	{
		write(1, " ", 1);
		flags->count++;
	}
	if (!flags->minus)
	{
		write (1, &c, 1);
		flags->count++;
	}
}
