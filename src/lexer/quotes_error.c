/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikkhach <mikkhach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 15:12:08 by mikkhach          #+#    #+#             */
/*   Updated: 2025/02/02 15:12:08 by mikkhach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	quotes_error(t_index_data *i_data, const char *s, t_commands *cmds)
{
	if (!s[i_data->i] && cmds->exit_value == 0)
	{
		cmds->exit_value = 2;
		ft_putstr_fd("-minishell: syntax error unclosed quotes\n", \
		STDERR);
	}
}
