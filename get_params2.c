/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_params2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepnovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 18:04:34 by arepnovs          #+#    #+#             */
/*   Updated: 2017/02/17 18:04:38 by arepnovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	get_pct(char *str, va_list args, int *ret)
{
	char	*pc;
	char	*z;
	int		i;
	int		f;

	i = 0;
	f = 1;
	z = ft_strnew(0);
	pc = ft_strnew(0);
	while (str[i])
	{
		while (str[i] && f <= 2)
		{
			pc = ft_charjoin(pc, str[i]);
			f = (str[i + 1] == '%') ? (f + 1) : f;
			i++;
		}
		if (check_specs(pc[ft_strlen(pc) - 1]) != 1
				|| (check_specs(pc[ft_strlen(pc) - 1]) == 1 && f >= 2))
			get_pct_parts(pc, args, ret);
		else
			get_specs(pc, args, ret, z);
		pc = ft_strnew(0);
		f = 1;
	}
}

void	get_pct_specs(char *set, va_list args, char *res, int *ret)
{
	t_specs params;
	t_flags flags;

	bzero_paraflags(&params, &flags);
	org_flags(get_flags(set), &flags);
	params.width = get_width(set);
	params.prec = get_precision(set);
	params.len = get_length(set);
	params.type = get_types(set);
	params.pct = res;
	go_to(args, params, flags, ret);
}

void	get_pct_parts(char *str, va_list args, int *ret)
{
	char	*res;
	char	*specs;
	int		i;
	int		f;

	i = 0;
	f = 0;
	specs = ft_strnew(0);
	while (f < 2 && str[i])
	{
		if (str[i] == '%')
			f++;
		if (f != 2)
			specs = ft_charjoin(specs, str[i]);
		i++;
	}
	res = ft_strsub(str, i - 1, ft_strlen(str));
	specs = ft_charjoin(specs, '%');
	get_pct_specs(specs, args, res, ret);
	free(specs);
	free(res);
}

void	get_wid(char *str, char **o_width, char **f_width, int *i)
{
	if ((str[(*i) - 1] < '0' || str[(*i) - 1] > '9') && str[*i] >= '0'
		&& str[*i] <= '9' && ft_strlen(*o_width) != 0)
	{
		if (ft_atoi(*o_width) != 0)
			*f_width = ft_strdup(*o_width);
		ft_bzero(*o_width, ft_strlen(*o_width));
	}
	if (str[*i] == '.')
	{
		(*i)++;
		while (str[*i] >= '0' && str[*i] <= '9')
			(*i)++;
	}
	else if ((str[*i] >= '0' && str[*i] <= '9') || (str[*i] == '0'
		&& str[(*i) + 1] >= '0' && str[(*i) + 1] <= '9'))
	{
		while (str[*i] >= '0' && str[*i] <= '9')
			*o_width = ft_charjoin(*o_width, str[(*i)++]);
		(*i)--;
	}
}

void	get_prec(char *str, char **o_prec, int *i)
{
	(*i)++;
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		*o_prec = ft_charjoin(*o_prec, str[*i]);
		(*i)++;
	}
	(*i)--;
}
