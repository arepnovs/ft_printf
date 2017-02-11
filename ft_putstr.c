/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepnovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 18:31:21 by arepnovs          #+#    #+#             */
/*   Updated: 2016/12/05 18:32:13 by arepnovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_putstr(char *str, t_specs params, int *ret)
{
	size_t	i;
    size_t  j;

    i = 0;
    if (params.width > ft_strlen(str))
        j = params.width;
    else
        j = ft_strlen(str);
    if (str[0] == '\0' && (params.type == 'c' || params.type == 'C'))
    {
        *ret = *ret + 1;
        write(1, &str[0], 1);
    }
	if (str)
	{
		while (i < j)
		{
			write(1, &str[i], 1);
			i++;
		}
        //if (params.type == c && ft_atoi(res) == 0 &&
        //write(1, &str[i], 1);
	}
}
