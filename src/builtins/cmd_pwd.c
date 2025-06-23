/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_pwd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikkhach <mikkhach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 15:10:03 by mikkhach          #+#    #+#             */
/*   Updated: 2025/02/02 15:18:55 by mikkhach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	cmd_pwd(void)
{
	char	*pwd;
	char	path[MAX_PATH];

	pwd = getcwd(path, MAX_PATH);
	if (pwd)
	{
		ft_putendl_fd(path, STDOUT_FILENO);
		return (EXIT_SUCCESS);
	}
	error_msg_cmd("pwd", NULL, strerror(errno), errno);
	return (EXIT_FAILURE);
}
