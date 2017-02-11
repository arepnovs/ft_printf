/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepnovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 17:57:04 by arepnovs          #+#    #+#             */
/*   Updated: 2016/12/10 14:16:29 by arepnovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	nbr_to_upstr(long long value, long long base, char **str)
{
    if (value >= base)
    {
        nbr_to_upstr(value / base, base, str);
        nbr_to_upstr(value % base, base, str);
    }
    else
    {
        if (value >= 10)
            **str = value + 'A' - 10;
        else
            **str = value + '0';
        (*str)++;
    }
}

void	nbr_to_lowstr(long long value, long long base, char **str)
{
    if (value >= base)
    {
        nbr_to_lowstr(value / base, base, str);
        nbr_to_lowstr(value % base, base, str);
    }
    else
    {
        if (value >= 10)
            **str = value + 'a' - 10;
        else
            **str = value + '0';
        (*str)++;
    }
}

char	*ft_itoa_long(long long value, int base, char mod)
{
    char	*str;
    char	*p;
    int		i;
    
    i = 0;
    str = (char*)malloc(sizeof(char) * 33);
    if (value - 1 == 9223372036854775807)
        return ("9223372036854775808");
    while (i < 33)
    {
        str[i] = 0;
        i++;
    }
    p = str;
    if (value < 0)
    {
        if (base == 10)
        {
            *p = '-';
            p++;
        }
        value *= -1;
    }
    if (base > 1 && base < 17 && mod == 'X')
        nbr_to_upstr((long long)value, (long long)base, &p);
    else if ((base > 1 && base < 17) || mod == 'x')
        nbr_to_lowstr((long long)value, (long long)base, &p);
    return (str);
}
