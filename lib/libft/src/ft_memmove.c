/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikkhach <mikkhach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 15:06:30 by mikkhach          #+#    #+#             */
/*   Updated: 2025/02/02 15:18:55 by mikkhach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *des, void *src, size_t len)
{
	unsigned int	i;

	if (des == NULL || src == NULL)
		return (NULL);
	if (des < src)
	{
		i = 0;
		while (i < len)
		{
			((char *) des)[i] = ((char *) src)[i];
			i++;
		}
	}
	else
	{
		i = len;
		while (i > 0)
		{
			((char *) des)[i - 1] = ((char *) src)[i - 1];
			i--;
		}
	}
	return (des);
}
