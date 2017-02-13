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

int     char_crutch(char* str)
{
    int i;
    
    i = 0;
    while (str[i])
    {
        if (str[i] != ' ')
            return (0);
        i++;
    }
    return(1);
}

void	ft_putcharf(char *str, t_specs params, int *ret)
{
	size_t	i;
    size_t  j;

    //i = (params.type == 'c' && params.width > 1) ? 1 : 0;
    i = 0;
    if (params.type == 'c' && params.width > 1 && char_crutch(str) == 1)
    {
        i = 1;
        j = params.width + 1;
    }
    else if (params.width > ft_strlen(str))
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
    }
}
