/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepnovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 18:38:54 by arepnovs          #+#    #+#             */
/*   Updated: 2017/02/17 18:39:58 by arepnovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int			ft_atoi(char *str)
{
	int	minus;
	int	res;

	minus = 0;
	res = 0;
	while (*str == ' ' || *str == '\t' || *str == '\v' || *str == '\r'
			|| *str == '\f' || *str == '\n')
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-')
	{
		minus = '1';
		str++;
	}
	while ((*str <= '9') && (*str >= '0'))
	{
		res = (res * 10) + (*str - '0');
		str++;
	}
	if (minus == '1')
		res = -res;
	return (res);
}

void		ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*tmp;

	i = 0;
	tmp = (char *)s;
	while (i < n)
	{
		tmp[i] = 0;
		i++;
	}
}

void		ft_putstr(char *str)
{
	size_t	i;

	i = 0;
	if (str)
	{
		while (str[i] != '\0')
		{
			write(1, &str[i], 1);
			i++;
		}
	}
}

int			ft_strcmp(const char *s1, const char *s2)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;
	if (s1 && s2)
	{
		while (str1[i] == str2[i] && (str1[i] != '\0' || str2[i] != '\0'))
		{
			if (str1[i] != str2[i])
				return (str1[i] - str2[i]);
			i++;
		}
		return (str1[i] - str2[i]);
	}
	else
		return (-1);
}

char		*ft_strdup(const char *s1)
{
	char	*str;
	size_t	i;

	i = 0;
	str = (char *)malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
