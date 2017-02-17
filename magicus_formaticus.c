/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   magicus_formaticus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepnovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 18:05:07 by arepnovs          #+#    #+#             */
/*   Updated: 2017/02/17 18:05:09 by arepnovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	first_symbol_alchemy(char **str, t_specs par, t_flags flags)
{
	if ((flags.minus == 1 && par.neg == 1) || (par.prec == 0 && par.neg == 1)
		|| par.neg == 1)
		*str[0] = '-';
	else if (flags.plus == 1 && par.neg != 1)
		*str[0] = '+';
	if (flags.space == 1 && par.neg != 1)
		*str[0] = ' ';
}

char	*res_transmut(char *str, t_specs p, t_flags flags, char *res)
{
	int len;
	int res_len;
	int i;

	i = (p.neg == 1) ? 1 : 0;
	res_len = ft_strlen(res);
	len = ft_strlen(str);
	while (str[i] != '\0')
	{
		if (p.prec != 0 || flags.plus == 1 || flags.space == 1)
		{
			while (i < len - res_len && len != res_len)
				i++;
		}
		str[i] = *res;
		i++;
		res++;
	}
	return (str);
}

char	*str_magic(t_specs p, t_flags flags, int res_len, char *res)
{
	char	*str;
	int		len;

	if (p.prec == -1 && (ft_strcmp(res, "0") == 0))
	{
		str = ft_strnew(0);
		if ((p.type == 'o' || p.type == 'O') && flags.hash == 1)
			return ("0");
		else if (p.type != 'p')
			return (str);
	}
	len = (p.prec > res_len) ? p.prec : res_len;
	if ((p.neg == 1 || ((flags.plus == 1 || flags.space == 1) && p.neg != 1))
		&& check_undef(p.type) == 0)
		len++;
	str = ft_strnew(len);
	ft_zero(str, len, '0');
	if (check_undef(p.type) == 0)
		first_symbol_alchemy(&str, p, flags);
	str = res_transmut(str, p, flags, res);
	if (p.type == 'p' || (flags.hash == 1 && ft_atoi(str) != 0 && (p.type == 'x'
		|| p.type == 'X' || p.type == 'o' || p.type == 'O')))
		str = prefix_witchery(str, p);
	return (str);
}

char	*sign_pref_enchant(char *res, char *str, t_flags flags)
{
	int len;
	int i;

	i = 0;
	len = ft_strlen(str);
	while (res[i])
	{
		if ((str[0] == '+' || str[0] == '-' || str[0] == ' ') && res[0] == '0')
		{
			res[0] = str[0];
			res[ft_strlen(res) - len] = '0';
		}
		else if (str[0] == ' ' && flags.zero != 1)
			i++;
		i++;
	}
	if ((str[1] == 'x' || str[1] == 'X') && res[0] == '0' && flags.zero != 0)
	{
		res[1] = str[1];
		res[ft_strlen(res) - len + 1] = '0';
	}
	return (res);
}

char	*str_sorcery(char *str, t_specs params, t_flags flags)
{
	char	*res;
	int		len;

	len = ft_strlen(str);
	res = ft_strnew(0);
	if (params.width >= len)
	{
		res = ft_strnew(params.width - len);
		if (params.prec == 0 && flags.zero == 1 && params.width > len)
			ft_zero(res, (params.width - len), '0');
		else if (params.width > len)
			ft_zero(res, (params.width - len), ' ');
		res = (flags.minus == 1) ? ft_strjoin(str, res) : ft_strjoin(res, str);
		sign_pref_enchant(res, str, flags);
	}
	else
		res = ft_strjoin(str, res);
	return (res);
}
