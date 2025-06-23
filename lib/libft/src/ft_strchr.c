/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikkhach <mikkhach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 15:07:18 by mikkhach          #+#    #+#             */
/*   Updated: 2025/02/02 15:18:55 by mikkhach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int argument)
{
	int	i;

	i = 0;
	if (!ft_isascii(argument))
		return ((char *) &str[i]);
	while (str[i])
	{
		if (str[i] == argument)
			return ((char *) &str[i]);
		i++;
	}
	if (argument == '\0')
		return ((char *) &str[i]);
	return (NULL);
}
