/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_handler.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikkhach <mikkhach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 15:13:52 by mikkhach          #+#    #+#             */
/*   Updated: 2025/02/02 15:18:55 by mikkhach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

bool	is_redirection_command(t_commands *cmds, int i)
{
	if (cmds->cmd[i].redirections[0])
		return (true);
	else
		return (false);
}

void	redirection_handler(t_commands *cmds, int j)
{
	int	i;
	int	status_code;

	i = 0;
	status_code = -1;
	while (cmds->cmd[j].redirections[i])
	{
		if (ft_strncmp(cmds->cmd[j].redirections[i], ">>", 2) == 0)
			status_code = rd_output_handler(cmds, cmds->cmd[j].redirections[i],
					false);
		else if (ft_strncmp(cmds->cmd[j].redirections[i], "<<", 2) == 0)
			rd_heredoc(cmds, cmds->cmd[j].redirections[i]);
		else if (ft_strncmp(cmds->cmd[j].redirections[i], "<", 1) == 0)
			status_code = rd_input_handler(cmds, cmds->cmd[j].redirections[i]);
		else if (ft_strncmp(cmds->cmd[j].redirections[i], ">", 1) == 0)
			status_code = rd_output_handler(cmds, cmds->cmd[j].redirections[i],
					true);
		cmds->io->cmd_index = j;
		if (status_code != -1)
			break ;
		i++;
	}
}
