/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikkhach <mikkhach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 15:49:04 by mikkhach          #+#    #+#             */
/*   Updated: 2025/02/02 15:49:06 by mikkhach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char	**split_args(char *command)
{
	return (ft_split(command, ' '));
}

char	*join_strs(char *str, char *add)
{
	char	*tmp;

	if (!add)
		return (str);
	if (!str)
		return (ft_strdup(add));
	tmp = str;
	str = ft_strjoin(tmp, add);
	free_ptr(tmp);
	return (str);
}

void	remove_quotes(char *str)
{
	char	last_reg;

	last_reg = 0;
	while (*str && !last_reg)
	{
		if (*str == '\'' || *str == '"')
		{
			last_reg = *str;
			ft_memmove(str, str + 1, ft_strlen(str + 1) + 1);
		}
		else
			str++;
	}
	while (*str && last_reg)
	{
		if (*str && *str == last_reg)
		{
			last_reg = 0;
			ft_memmove(str, str + 1, ft_strlen(str + 1) + 1);
		}
		else
			str++;
	}
	if (*str)
		return (remove_quotes(str));
}
