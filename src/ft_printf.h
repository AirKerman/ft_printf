/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkerman <rkerman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 19:06:57 by rkerman           #+#    #+#             */
/*   Updated: 2024/11/22 22:01:21 by rkerman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

typedef struct s_list
{
	int		minus;
	int		zero;
	int		precision;
	int		hash;
	int		space;
	int		plus;
	int		width;
	int		wzero;
	int		count;
	int		len;
	int		printzero;
	int		on;
	char	type;
}	t_flags;

int		ft_printf(const char *format, ...);
void	print_s(char *s, t_flags *flags);
void	print_c(int c, t_flags *flags);
void	print_pe(t_flags *flags);
void	print_di(int n, t_flags *flags);
void	print_p(unsigned long p, t_flags *flags);
void	print_u(unsigned int n, t_flags *flags);
void	print_x(unsigned int n, t_flags *flags);
void	display_error(t_flags *flags);
void	display_extra(int n, t_flags *flags);
void	display_args(va_list ap, t_flags *flags);
void	width_calculator(t_flags *flags);
int		parse_format(va_list *ap, t_flags *fl, const char **f);
int		lenint(int n);
void	init_flags(t_flags *flags);

#endif
