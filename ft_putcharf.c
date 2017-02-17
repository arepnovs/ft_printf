/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putcharf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepnovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 17:44:48 by arepnovs          #+#    #+#             */
/*   Updated: 2017/02/17 18:38:16 by arepnovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int		char_crutch(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\0' && str[i] != '0')
			return (0);
		i++;
	}
	return (1);
}

static void		get_char_sets(char *str, t_specs params, size_t *i, size_t *j)
{
	int len;

	len = ft_strlen(str);
	if (params.type == 'c' && params.width > 2 && char_crutch(str) == 1)
	{
		*i = 1;
		*j = params.width + 1;
	}
	else if (params.width > len)
		*j = params.width;
	else if (len > 2 && char_crutch(str) == 1)
	{
		*i = 1;
		*j = len + 1;
	}
	else
		*j = len;
}

void			ft_putcharf(char *str, t_specs params, int *ret)
{
	size_t	i;
	size_t	j;
	int		len;

	len = ft_strlen(str);
	i = 0;
	get_char_sets(str, params, &i, &j);
	if (str[0] == '\0')
	{
		*ret = *ret + 1;
		write(1, &str[0], 1);
	}
	else if (params.width >= 2 && len == 1)
		*ret = *ret + 1;
	if (str)
	{
		while (i < j)
		{
			write(1, &str[i], 1);
			i++;
		}
	}
}
