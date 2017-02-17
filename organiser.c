/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   organiser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepnovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 18:04:59 by arepnovs          #+#    #+#             */
/*   Updated: 2017/02/17 18:05:01 by arepnovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		len_cmp(int a, int b, int c)
{
	if (a >= b && a >= c)
		return (a);
	else if (b >= a && b >= c)
		return (b);
	else
		return (c);
}

void	ft_zero(void *s, size_t n, char c)
{
	size_t	i;
	char	*tmp;

	i = 0;
	tmp = (char *)s;
	while (i < n)
	{
		tmp[i] = c;
		i++;
	}
	tmp[i] = '\0';
}

void	bzero_paraflags(t_specs *params, t_flags *flag)
{
	params->width = 0;
	params->prec = 0;
	params->neg = 0;
	params->len = ft_strnew(0);
	flag->space = 0;
	flag->zero = 0;
	flag->plus = 0;
	flag->minus = 0;
	flag->hash = 0;
}

void	org_flags(char *str, t_flags *flag)
{
	while (*str)
	{
		if (*str == ' ')
			flag->space = 1;
		if (*str == '0')
			flag->zero = 1;
		if (*str == '+')
			flag->plus = 1;
		if (*str == '-')
			flag->minus = 1;
		if (*str == '#')
			flag->hash = 1;
		str++;
	}
	if (flag->zero == 1 && flag->minus == 1)
		flag->zero = 0;
	if (flag->space == 1 && flag->plus == 1)
		flag->space = 0;
}
