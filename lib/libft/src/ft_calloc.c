/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikkhach <mikkhach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 15:05:34 by mikkhach          #+#    #+#             */
/*   Updated: 2025/02/02 15:18:55 by mikkhach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nitems, size_t len)
{
	void	*ptr;
	size_t	lentotal;

	if (nitems >= INT_MAX || len >= INT_MAX)
		return (NULL);
	lentotal = nitems * len;
	ptr = malloc(lentotal);
	if (ptr == NULL)
		return (NULL);
	ft_memset(ptr, 0, lentotal);
	return (ptr);
}
