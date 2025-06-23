/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikkhach <mikkhach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 15:09:49 by mikkhach          #+#    #+#             */
/*   Updated: 2025/02/02 15:18:55 by mikkhach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	cmd_env(t_data *data, t_commands *cmds, int num_cmd)
{
	int		i;

	if (cmds->cmd[num_cmd].args[1])
		return (error_msg_cmd("env", NULL, "too many arguments", STDERR));
	if (!data->env)
		return (EXIT_FAILURE);
	i = 0;
	while (data->env[i])
	{
		if (ft_strchr(data->env[i], '='))
			ft_putendl_fd(data->env[i], STDOUT_FILENO);
		i++;
	}
	return (EXIT_SUCCESS);
}
