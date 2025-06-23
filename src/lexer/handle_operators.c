/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_operators.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikkhach <mikkhach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 15:11:45 by mikkhach          #+#    #+#             */
/*   Updated: 2025/02/02 15:56:22 by mikkhach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	operators_errors(const char *s, t_commands *cmds, t_index_data \
							*i_data)
{
	if (cmds->exit_value == 0 && s[i_data->i])
	{
		cmds->exit_value = 2;
		ft_putstr_fd("-minishell: syntax error near unexpected token `", \
		STDERR);
		while (s[i_data->i] && (s[i_data->i] == '&' || s[i_data->i] == '|'))
			ft_putchar_fd(s[i_data->i++], STDERR);
		ft_putstr_fd("'\n", STDERR);
	}
	if (cmds->exit_value == 0 && !s[i_data->i])
	{
		cmds->exit_value = error_msg_cmd(NULL, NULL, \
		"-minishell: syntax error not expecting newline", 2);
	}
}

void	lexer_operators(const char *s, t_commands *cmds)
{
	t_index_data	i_data;

	i_data.i = 0;
	while (s[i_data.i] && s[i_data.i] == ' ')
		i_data.i++;
	if (s[i_data.i] == '&' || s[i_data.i] == '|')
	{
		operators_errors(s, cmds, &i_data);
	}
	else
	{
		while (s[i_data.i])
		{
			if (s[i_data.i] && (s[i_data.i] == '&' || s[i_data.i] == '|'))
			{
				i_data.i++;
				while (s[i_data.i] && s[i_data.i] == ' ')
					i_data.i++;
				if (!s[i_data.i])
					operators_errors(s, cmds, &i_data);
			}
			else
				i_data.i++;
		}
	}
}
