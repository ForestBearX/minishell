/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikkhach <mikkhach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 15:06:53 by mikkhach          #+#    #+#             */
/*   Updated: 2025/02/02 15:18:55 by mikkhach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	nblong;
	int		i;
	char	c[10];

	nblong = n;
	if (nblong == 0)
		ft_putchar_fd('0', fd);
	i = 0;
	if (nblong < 0)
	{
		ft_putchar_fd('-', fd);
		nblong = nblong * -1;
	}
	while (nblong > 0)
	{
		c[i] = nblong % 10 + 48;
		nblong = nblong / 10;
		i++;
	}
	i--;
	while (i >= 0)
	{
		ft_putchar_fd(c[i], fd);
		i--;
	}
}
