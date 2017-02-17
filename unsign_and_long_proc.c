/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsign_and_long_proc.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepnovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 18:07:24 by arepnovs          #+#    #+#             */
/*   Updated: 2017/02/17 18:07:26 by arepnovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

unsigned long long	proc_unlen2(va_list args, t_specs params)
{
	unsigned long long	ull;

	ull = 0;
	if (ft_strcmp(params.len, "l") == 0)
		ull = (unsigned long long)va_arg(args, unsigned long);
	else if (ft_strcmp(params.len, "ll") == 0)
		ull = va_arg(args, unsigned long long);
	else if (ft_strcmp(params.len, "j") == 0)
		ull = (unsigned long long)va_arg(args, uintmax_t);
	else if (ft_strcmp(params.len, "z") == 0)
		ull = (unsigned long long)va_arg(args, size_t);
	else if (ft_strcmp(params.len, "t") == 0)
		ull = (unsigned long long)va_arg(args, ptrdiff_t);
	return (ull);
}

unsigned long long	proc_unlen(va_list args, t_specs p)
{
	unsigned char		c;
	unsigned short int	s_i;

	if (p.len)
	{
		if (ft_strcmp(p.len, "hh") == 0 && (p.type != 'O' && p.type != 'U'))
		{
			c = (unsigned char)va_arg(args, unsigned int);
			return ((unsigned long long)c);
		}
		else if (ft_strcmp(p.len, "h") == 0 && p.type != 'O'
				&& p.type != 'U')
		{
			s_i = (unsigned short int)va_arg(args, unsigned int);
			return ((unsigned long long)s_i);
		}
		else if (ft_strcmp(p.len, "l") == 0 || ft_strcmp(p.len, "ll") == 0
			|| ft_strcmp(p.len, "j") == 0 || ft_strcmp(p.len, "z") == 0
			|| ft_strcmp(p.len, "t") == 0)
			return (proc_unlen2(args, p));
	}
	return ((p.type == 'O' || p.type == 'U') ?
			(unsigned long long)va_arg(args, unsigned long)
			: (unsigned long long)va_arg(args, unsigned int));
}

void				print_unint(va_list args, t_specs p, t_flags f, int *ret)
{
	char *res;
	char *str;

	res = NULL;
	if (p.type == 'x' || p.type == 'X')
		res = ft_itoa_unsigned(proc_unlen(args, p), 16, p.type);
	else if (p.type == 'o' || p.type == 'O')
		res = ft_itoa_unsigned(proc_unlen(args, p), 8, p.type);
	else if (p.type == 'u' || p.type == 'U')
		res = ft_itoa_unsigned(proc_unlen(args, p), 10, p.type);
	else if (p.type == 'u')
		res = ft_itoa_unsigned(proc_unlen(args, p), 2, p.type);
	str = proc_width(p, f, res);
	*ret = *ret + ((str[0] == '\0') ? 0 : ft_strlen(str));
	ft_putstr(str);
}
