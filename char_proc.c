/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_proc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepnovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 18:03:53 by arepnovs          #+#    #+#             */
/*   Updated: 2017/02/17 18:04:14 by arepnovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*ft_itow(int wch)
{
	char			*res;
	unsigned char	tw[3];
	unsigned char	tr[4];

	if (wch < 128)
	{
		res = ft_strnew(2);
		res[0] = wch;
		return (res);
	}
	if (wch > 127 && wch < 2048)
	{
		tw[0] = (wch >> 6) + 192;
		tw[1] = (wch << 2);
		tw[1] = (tw[1] >> 2) + 128;
		tw[2] = '\0';
		return (ft_strdup((char *)tw));
	}
	tr[0] = (wch >> 12) + 224;
	tr[1] = (wch >> 6) << 2;
	tr[1] = (tr[1] >> 2) + 128;
	tr[2] = (wch << 2);
	tr[2] = (tr[2] >> 2) + 128;
	tr[3] = '\0';
	return (ft_strdup((char *)tr));
}

char	*ft_itowstr(int *wch, int prec)
{
	int		i;
	int		len;
	char	*str;
	char	*symb;

	str = ft_strnew(0);
	len = 0;
	i = 0;
	if (!wch)
		return ("(null)");
	while (wch[i])
	{
		symb = ft_itow(wch[i]);
		if (prec > 0)
		{
			len = len + ft_strlen(symb);
			if (len <= prec)
				str = ft_strjoin(str, symb);
		}
		else
			str = ft_strjoin(str, symb);
		i++;
	}
	return (str);
}

void	get_char(char **str, va_list args, t_specs params)
{
	if (params.type == 'c' || params.type == 'C')
	{
		if (ft_strcmp(params.len, "l") != 0)
			*(str[0]) = (char)va_arg(args, int);
		else
			*str = ft_itow(va_arg(args, int));
	}
	else if (params.type == 's' || params.type == 'S')
	{
		if (params.type == 'S' || ft_strcmp(params.len, "l") == 0)
			*str = ft_itowstr(va_arg(args, int*), params.prec);
		else
			*str = va_arg(args, char*);
		if (*str == NULL && params.width > 1)
			*str = ft_strnew(0);
		else if (*str == NULL)
			*str = "(null)";
	}
}

void	print_char(va_list args, t_specs params, t_flags flags, int *ret)
{
	char	*str;
	int		res_len;

	str = ft_strnew(0);
	if (params.type != '%')
		get_char(&str, args, params);
	else
		str = params.pct;
	res_len = (str == NULL || (ft_strcmp(str, "(null)")) == 0) ? 0
		: ft_strlen(str);
	str = char_voodoo(params, flags, str, res_len);
	*ret = *ret + ft_strlen(str);
	(params.type == 'c' || params.type == 'C') ? ft_putcharf(str, params, ret)
		: ft_putstr(str);
}
