/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikkhach <mikkhach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 15:07:44 by mikkhach          #+#    #+#             */
/*   Updated: 2025/02/02 15:53:07 by mikkhach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *des, const char *src, size_t len)
{
	size_t			lensrc;
	unsigned int	i;

	i = 0;
	if (!des || !src)
		return (0);
	lensrc = ft_strlen(src);
	if (len <= 0)
		return (lensrc);
	while (src[i] != '\0' && (i < (len - 1)))
	{
		des[i] = src[i];
		i++;
	}
	des[i] = '\0';
	return (lensrc);
}
