/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_help2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepnovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 17:47:20 by arepnovs          #+#    #+#             */
/*   Updated: 2017/02/17 17:47:33 by arepnovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		check_pcpc(char c)
{
	char	*check;
	int		i;

	i = 0;
	check = "sSpdDioOuUxXcCb+-0 #hlLjzt";
	while (*check)
	{
		if (*check == c)
			return (1);
		check++;
	}
	return (0);
}

int		check_wrong(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
		{
			if (check_pcpc(str[i]) == 0 && str[i] != '.' && str[i] != '%')
				return (i);
		}
		i++;
	}
	return (-1);
}

int		check_pct(char *str)
{
	int i;
	int p;

	p = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
			p++;
		i++;
	}
	return ((p > 1) ? 1 : 0);
}

int		check_undef(char c)
{
	char	*specs;
	int		i;

	i = 0;
	specs = "poOuUxXb";
	while (*specs)
	{
		if (*specs == c)
			return (1);
		specs++;
	}
	return (0);
}
