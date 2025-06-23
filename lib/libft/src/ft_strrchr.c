/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikkhach <mikkhach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 15:08:06 by mikkhach          #+#    #+#             */
/*   Updated: 2025/02/02 15:18:55 by mikkhach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(char *str, int argument)
{
	int	length;

	length = ft_strlen(str);
	if (!ft_isascii(argument))
		return ((char *) &str[0]);
	while (length >= 0)
	{
		if (str[length] == argument)
			return ((char *) &str[length]);
		length--;
	}
	return ((void *) 0);
}
