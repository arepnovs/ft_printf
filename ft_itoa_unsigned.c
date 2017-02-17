/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_unsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepnovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 17:10:09 by arepnovs          #+#    #+#             */
/*   Updated: 2017/02/17 18:36:37 by arepnovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void	nbr_upstr(unsigned long long value, unsigned long long base,
		char **str)
{
	if (value >= base)
	{
		nbr_upstr(value / base, base, str);
		nbr_upstr(value % base, base, str);
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

static void	nbr_lwstr(unsigned long long value, unsigned long long base,
		char **str)
{
	if (value >= base)
	{
		nbr_lwstr(value / base, base, str);
		nbr_lwstr(value % base, base, str);
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

char		*ft_itoa_unsigned(unsigned long long value, int base, char mod)
{
	char	*str;
	char	*p;
	int		i;

	i = 0;
	str = (char*)malloc(sizeof(char) * 33);
	while (i < 33)
	{
		str[i] = 0;
		i++;
	}
	p = str;
	if (base > 1 && base < 17 && mod == 'X')
		nbr_upstr((unsigned long long)value, (unsigned long long)base, &p);
	else if ((base > 1 && base < 17) || mod == 'x')
		nbr_lwstr((unsigned long long)value, (unsigned long long)base, &p);
	return (str);
}
