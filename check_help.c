/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_help.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepnovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 17:50:52 by arepnovs          #+#    #+#             */
/*   Updated: 2017/02/17 17:50:55 by arepnovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		check_rep(char *str, char c, int j)
{
	int i;

	if (j == 0)
		i = 1;
	else
		i = 0;
	while (str[i] && i < j)
	{
		if (str[i] == c)
			return (0);
		i++;
	}
	return (1);
}

int		check_flags(char c)
{
	char	*flags;
	int		i;

	i = 0;
	flags = "+-0 #";
	while (flags[i])
	{
		if (flags[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int		check_len(char c)
{
	char	*len;
	int		i;

	i = 0;
	len = "hlLjzt";
	while (*len)
	{
		if (*len == c)
			return (1);
		len++;
	}
	return (0);
}

int		check_specs(char c)
{
	char	*specs;
	int		i;

	i = 0;
	specs = "sSpdDioOuUxXcCb";
	while (*specs)
	{
		if (*specs == c)
			return (1);
		specs++;
	}
	return (0);
}
