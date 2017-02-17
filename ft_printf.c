/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pr1.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepnovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 17:51:35 by arepnovs          #+#    #+#             */
/*   Updated: 2017/02/17 17:52:29 by arepnovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	go_to(va_list args, t_specs params, t_flags flags, int *ret)
{
	if (params.type == 'd' || params.type == 'D'
			|| params.type == 'i' || params.type == 'p')
		print_int(args, params, flags, ret);
	else if (params.type == 'x' || params.type == 'X' || params.type == 'o'
			|| params.type == 'O' || params.type == 'u' || params.type == 'U'
			|| params.type == 'b')
		print_unint(args, params, flags, ret);
	else if (params.type == 'c' || params.type == 'C'
			|| params.type == 's' || params.type == 'S')
		print_char(args, params, flags, ret);
	else if (params.type == '%')
		print_char(args, params, flags, ret);
}

void	get_specs(char *set, va_list args, int *ret, char *z)
{
	t_specs params;
	t_flags flags;
	char	*s;

	bzero_paraflags(&params, &flags);
	org_flags(get_flags(set), &flags);
	params.width = get_width(set);
	params.prec = get_precision(set);
	params.len = get_length(set);
	params.type = get_types(set);
	if (check_wrong(set) != -1)
	{
		params.type = 's';
		set = ft_strsub(set, check_wrong(set), ft_strlen(set));
		z = ft_charjoin(z, set[0]);
		params.prec = (params.prec == -1) ? 0 : params.prec;
		s = char_voodoo(params, flags, z, 1);
		set++;
		*ret = *ret + ft_strlen(set) + ft_strlen(s);
		s = ft_strjoin(s, set);
		ft_putstr(s);
		params.type = 'z';
	}
	go_to(args, params, flags, ret);
}

void	get_sets(va_list args, const char *format, int *i, int *ret)
{
	char	*set;
	char	*z;

	z = ft_strnew(0);
	set = ft_strnew(0);
	while (check_specs(format[*i]) != 1 && format[*i] != '\0')
	{
		set = ft_charjoin(set, format[*i]);
		(*i)++;
	}
	if (check_specs(format[*i]) == 1 || format[*i] == '%')
		set = ft_charjoin(set, format[*i]);
	if (ft_strlen(set) == 2 && check_specs(set[1]) != 1
		&& set[1] != '%')
		*i = *i - 2;
	else if (set[1] != '\0')
		(check_pct(set) == 0) ? get_specs(set, args, ret, z)
	: get_pct(set, args, ret);
	free(set);
}

int		get_args(va_list args, const char *format)
{
	int		i;
	int		len;
	int		ret;

	i = 0;
	ret = 0;
	len = ft_strlen(format);
	while (format[i] != '\0' && i < len)
	{
		while (format[i] != '%' && i < len && format[i] != '\0')
		{
			write(1, &format[i], 1);
			i++;
			ret++;
		}
		if (format[i] == '%' && format[i] != '\0' && i < len)
			get_sets(args, format, &i, &ret);
		i++;
	}
	return (ret);
}

int		ft_printf(const char *format, ...)
{
	int		i;
	va_list	args;

	i = 0;
	if (format)
	{
		va_start(args, format);
		i = get_args(args, format);
		va_end(args);
	}
	return (i);
}
