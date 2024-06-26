#include "minishell.h"

static t_token	*get_token(char *input, int *i)
{
	t_token	*new;

	while (input[*i] && ft_isblank(input[*i]))
		(*i)++;
	if (!input[*i])
		return (NULL);
	new = malloc(sizeof(t_token));
	if (!new)
		exit_program(OUT_OF_MEMORY);
	*new = (t_token){0};
	if (is_pipe(input[*i]))
		new->str = set_pipe_token(input, i, new);
	else if (is_bracket(input[*i]))
		new->str = set_redirector_token(input, i, new);
	else
		new->str = set_str_token(input, i);
	return (new);
}

int	void_filterer(t_token *tok)
{
	t_token	*temp;
	int		returned;

	returned = 0;
	while (tok)
	{
		if (tok->str && tok->str[0] == '\0')
		{
			if (!tok->prev && tok->next)
				temp = tok->next->next;
			else
				temp = tok->prev;
			remove_token(tok);
			tok = temp;
			while (temp && temp->prev)
				temp = temp->prev;
			if (temp)
				get_control()->tokens = temp;
			returned = 1;
		}
		else if (tok)
			tok = tok->next;
	}
	return (returned);
}

int	tokenization(char *input)
{
	t_ctrl	*control;
	t_token	*current;
	int		i;

	if (!input)
		return (0);
	i = 0;
	control = get_control();
	control->tokens = get_token(input, &i);
	if (!control->tokens)
		return (0);
	while (input[i])
	{
		current = get_token(input, &i);
		link_token(current, control->tokens);
	}
	return (0);
}
