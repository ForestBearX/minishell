/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikkhach <mikkhach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 15:11:08 by mikkhach          #+#    #+#             */
/*   Updated: 2025/02/02 15:18:55 by mikkhach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

bool	valid_args(int argc, char **argv)
{
	if (argc > 1 || !argv)
	{
		ft_putendl_fd("Invalid Arguments", STDOUT_FILENO);
		return (false);
	}
	return (true);
}

bool	just_space_string(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isspace(str[i]))
			return (false);
		i++;
	}
	return (true);
}
