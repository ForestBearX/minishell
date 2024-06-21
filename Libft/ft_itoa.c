/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikkhach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 14:34:53 by mikkhach          #+#    #+#             */
/*   Updated: 2023/03/16 14:35:13 by mikkhach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long int	counter(int n)
{
	int	i;

	i = 0;
	if (n <= 0)
	{
		i = 1;
	}
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static char	*array(unsigned int n, char *ar, long int len)
{
	while (n > 0)
	{
		ar[len--] = (n % 10) + '0';
		n = n / 10;
	}
	return (ar);
}

char	*ft_itoa(int n)
{
	char			*str;
	long int		len;
	unsigned int	nb;

	len = counter(n);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	if (n == 0)
		str[0] = '0';
	if (n < 0)
	{
		str[0] = '-';
		nb = (unsigned int)n * (-1);
	}
	else
		nb = (unsigned int)n;
	str[len--] = '\0';
	array(nb, str, len);
	return (str);
}
