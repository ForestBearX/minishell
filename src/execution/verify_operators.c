/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_operators.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikkhach <mikkhach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 15:10:45 by mikkhach          #+#    #+#             */
/*   Updated: 2025/02/02 15:18:55 by mikkhach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	verify_or(t_data *data, t_commands *cmds, int num_cmd)
{
	int	i;

	i = num_cmd;
	if (g_status_code == 0)
	{
		while (cmds->operators[i - 1] && cmds->operators[i - 1] == OR)
		{
			init_single_cmd(data, cmds, i);
			i++;
		}
		cmds->num_exec = i;
		init_cmd(data, cmds, i);
	}
	else
		init_cmd(data, cmds, num_cmd);
}

static void	verify_and(t_data *data, t_commands *cmds, int num_cmd)
{
	int	i;

	i = num_cmd;
	if (g_status_code != 0)
	{
		while (cmds->operators[i - 1] && cmds->operators[i - 1] == AND)
		{
			init_single_cmd(data, cmds, i);
			i++;
		}
		cmds->num_exec = i;
		init_cmd(data, cmds, i);
	}
	else
		init_cmd(data, cmds, num_cmd);
}

void	verify_operators(t_data *data, t_commands *cmds, int num_cmd)
{
	if (cmds->operators[num_cmd - 1] == OR)
		verify_or(data, cmds, num_cmd);
	if (cmds->operators[num_cmd - 1] == AND)
		verify_and(data, cmds, num_cmd);
}
