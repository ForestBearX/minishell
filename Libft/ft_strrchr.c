/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikkhach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 16:22:38 by mikkhach          #+#    #+#             */
/*   Updated: 2023/03/09 16:23:42 by mikkhach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	l;

	l = (int)ft_strlen((char *)s);
	while (l >= 0)
	{
		if (s[l] == (char)c)
		{
			return ((char *)(s + l));
		}
		l--;
	}
	return (0);
}
