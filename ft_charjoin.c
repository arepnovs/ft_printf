/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepnovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 17:30:20 by arepnovs          #+#    #+#             */
/*   Updated: 2016/12/10 14:24:41 by arepnovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

char		*ft_charjoin(const char *s1, const char s2)
{
	size_t	i;
	size_t	j;
	char	*res;

	i = 0;
	if (s1 && s2)
	{
		res = (char *)malloc((ft_strlen(s1) +
					2) * sizeof(char));
		if (!res)
			return (NULL);
		while (s1[i] != '\0')
		{
			res[i] = s1[i];
			i++;
		}
        res[i] = s2;
        i++;
		res[i] = '\0';
		return (res);
	}
	return (NULL);
}
