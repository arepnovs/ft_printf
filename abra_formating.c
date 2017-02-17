/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   abra_formating.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepnovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 18:03:04 by arepnovs          #+#    #+#             */
/*   Updated: 2017/02/17 18:03:23 by arepnovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*prefix_witchery(char *str, t_specs par)
{
	char *bigx_pref;
	char *lilx_pref;
	char *o_pref;

	bigx_pref = ft_strnew(2);
	lilx_pref = ft_strnew(2);
	o_pref = ft_strnew(1);
	bigx_pref = "0X";
	lilx_pref = "0x";
	o_pref = "0";
	if (par.type == 'x' || par.type == 'p')
		str = ft_strjoin(lilx_pref, str);
	else if (par.type == 'X')
		str = ft_strjoin(bigx_pref, str);
	else if ((par.type == 'o' || par.type == 'O') && (par.width >= par.prec))
		str = ft_strjoin(o_pref, str);
	return ((par.type == 'p' && par.prec == -1) ? lilx_pref : str);
}

char	*char_kadabra(t_specs p, t_flags flags, int len)
{
	char *ftr;

	ftr = (p.type == '%' || (p.type == 'c' && p.width <= 2))
		? ft_strnew(p.width - 1) : ft_strnew(p.width - len);
	if (flags.zero == 1)
		ft_zero(ftr, (p.type == '%' || (p.type == 'c' && p.width <= 2))
			? (p.width - 1) : (p.width - len), '0');
	else
		ft_zero(ftr, (p.type == '%' || (p.type == 'c' && p.width <= 2))
			? (p.width - 1) : (p.width - len), ' ');
	return (ftr);
}

char	*char_voodoo(t_specs p, t_flags flags, char *str, int res_len)
{
	char	*ftr;
	int		len;

	if (p.prec == -1 && ft_strlen(str) == 0)
	{
		str = ft_strnew(0);
		if ((p.type != 'c' && p.width > 1) && (p.type != 's' && p.width < 1))
			return (str);
	}
	if (p.prec == -1 && (p.type == 's' || p.type == 'S'))
		str = ft_strnew(0);
	if (p.prec > 0 && res_len > p.prec && (p.type != 'c' || p.type != 'C'))
		str = ft_strsub(str, 0, p.prec);
	len = ft_strlen(str);
	if (p.width > 1 && p.width > len)
	{
		ftr = char_kadabra(p, flags, len);
		str = (flags.minus == 1) ? ft_strjoin(str, ftr) : ft_strjoin(ftr, str);
	}
	return (str);
}
