/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parser.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkerman <rkerman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 15:40:29 by rkerman           #+#    #+#             */
/*   Updated: 2024/11/22 21:54:51 by rkerman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	is_type(char c)
{
	if (c == 'c' || c == 's' || c == 'p'
		|| c == 'd' || c == 'i' || c == 'u'
		|| c == 'x' || c == 'X' || c == '%')
		return (1);
	return (0);
}

static int	is_flag(char c)
{
	if (c == '0' || c == ' ' || c == '-'
		|| c == '#' || c == '+')
		return (1);
	return (0);
}

static int	ft_printf_atoi(va_list *ap, const char *str, int *i, t_flags *flags)
{
	int	number;

	number = 0;
	if (str[*i] && str[*i] == '*')
	{
		number = va_arg(*ap, int);
		if (number < 0 && !flags->precision)
		{
			number *= -1;
			flags->minus = 1;
		}
		else if (number < 0 && flags->precision)
		{
			flags->precision = 0;
			(*i)++;
			return (0);
		}
		(*i)++;
	}
	while (str[*i] && (str[*i] >= '0' && str[*i] <= '9'))
	{
		number = (number * 10) + (str[*i] - 48);
		(*i)++;
	}
	return (number);
}

static void	parse_flags(t_flags *flags, int *i, const char **f)
{
	while ((*f)[*i] && is_flag((*f)[*i]))
	{
		if ((*f)[*i] == '0')
			flags->zero = 1;
		else if ((*f)[*i] == '-')
			flags->minus = 1;
		else if ((*f)[*i] == '#')
			flags->hash = 1;
		else if ((*f)[*i] == ' ')
			flags->space = 1;
		else if ((*f)[*i] == '+')
			flags->plus = 1;
		(*i)++;
	}
}

int	parse_format(va_list *ap, t_flags *fl, const char **f)
{
	int	i;

	i = 1;
	parse_flags(fl, &i, f);
	if (((*f)[i] >= '1' && (*f)[i] <= '9') || (*f)[i] == '*')
		fl->width = ft_printf_atoi(&*ap, *f, &i, &*fl);
	if ((*f)[i] == '.')
	{
		fl->precision = 1;
		i++;
	}
	if (((*f)[i] >= '0' && (*f)[i] <= '9') || ((*f)[i] == '*' && fl->precision))
		fl->wzero = ft_printf_atoi(&*ap, *f, &i, &*fl);
	if (is_type((*f)[i]))
	{
		fl->type = (*f)[i];
		*f += i;
		return (1);
	}
	return (0);
}
