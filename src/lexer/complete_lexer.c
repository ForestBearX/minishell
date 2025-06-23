/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complete_lexer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikkhach <mikkhach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 15:11:37 by mikkhach          #+#    #+#             */
/*   Updated: 2025/02/02 15:11:37 by mikkhach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	copy_quotes(char const *s, char **str, t_temp_index *data)
{
	str[data->j][data->o++] = s[data->i++];
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
	str[data->j][data->o++] = s[data->i++];
}

static void	ft_strcpy(char const *s, char **str, t_temp_index *data)
{
	data->o = 0;
	while (s[data->i] && s[data->i] != '&' && s[data->i] != '|')
	{
		if (s[data->i] == '\'' || s[data->i] == '\"')
			copy_quotes(s, str, data);
		if (s[data->i])
			str[data->j][data->o++] = s[data->i++];
	}
	if (s[data->i])
		data->i++;
	if (s[data->i] && s[data->i - 1] == '&' && s[data->i] == '&')
		data->i++;
	if (s[data->i] && s[data->i - 1] == '|' && s[data->i] == '|')
		data->i++;
	while ((s[data->i] && s[data->i] == '|') || s[data->i] == '&' \
			|| s[data->i] == ' ')
		data->i++;
}

void	putchar_lexer(char const *s, char **str, size_t countc)
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
