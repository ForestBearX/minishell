/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complete_redirections.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikkhach <mikkhach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 15:12:29 by mikkhach          #+#    #+#             */
/*   Updated: 2025/02/02 15:12:29 by mikkhach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	handle_quotes(t_temp_index *data, char *s, char special_char)
{
	data->i++;
	while (s[data->i] && s[data->i] != special_char)
		data->i++;
	data->i++;
}

static void	copy_quotes(char *s, char **str, t_temp_index *data)
{
	data->i++;
	if (s[data->i - 1] == '\'')
	{
		while (s[data->i] && s[data->i] != '\'')
			str[data->j][data->o++] = s[data->i++];
	}
	else
	{
		while (s[data->i] && s[data->i] != '\"')
			str[data->j][data->o++] = s[data->i++];
	}
	data->i++;
}

static void	ft_strcpy(char *s, char **str, t_temp_index *data)
{
	data->o = 0;
	while (s[data->i] && (s[data->i] != '<' && s[data->i] != '>'))
	{
		if (s[data->i] == '\'' || s[data->i] == '\"')
			handle_quotes(data, s, s[data->i]);
		else
			data->i++;
	}
	while (s[data->i] && (s[data->i] == '<' || s[data->i] == '>' || \
			s[data->i] == ' ' ))
		str[data->j][data->o++] = s[data->i++];
	while (s[data->i] && s[data->i] != ' ')
	{
		if (s[data->i] == '\'' || s[data->i] == '\"')
			copy_quotes(s, str, data);
		else
			str[data->j][data->o++] = s[data->i++];
	}
}

void	putchar_redirection(char *s, char **str, size_t countc)
{
	t_temp_index	data;

	data.i = 0;
	data.j = 0;
	while (data.j < countc)
	{
		ft_strcpy(s, str, &data);
		data.j++;
	}
	str[data.j] = NULL;
}
