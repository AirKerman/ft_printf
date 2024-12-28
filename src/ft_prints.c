/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prints.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkerman <rkerman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 19:54:18 by rkerman           #+#    #+#             */
/*   Updated: 2024/11/22 21:37:57 by rkerman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	printf_strlen(char *str, t_flags *flags)
{
	int	i;

	i = 0;
	while (str && str[i])
		i++;
	if (flags->precision && i > flags->wzero)
		flags->len = flags->wzero;
	else
		flags->len = i;
	if (flags->width > flags->len)
		flags->width -= flags->len;
	else
		flags->width = 0;
	if (!str && flags->width >= 6 && ((flags->precision && flags->wzero >= 6)
			|| !flags->precision))
		flags->width -= 6;
	else if (!str && flags->width < 6
		&& ((flags->precision && flags->wzero >= 6) || !flags->precision))
		flags->width = 0;
	flags->count += flags->len + flags->width;
}

void	print_s(char *s, t_flags *flags)
{
	int	i;

	i = 0;
	printf_strlen(s, &*flags);
	if (!s && flags->minus)
		display_error(&*flags);
	else if (s && flags->minus)
	{
		while (s[i] && i < flags->len)
			write(1, &s[i++], 1);
	}
	while (flags->width--)
		write(1, " ", 1);
	if (!s && !flags->minus)
		display_error(&*flags);
	else if (s && !flags->minus)
	{
		while (s[i] && i < flags->len)
			write(1, &s[i++], 1);
	}
}
