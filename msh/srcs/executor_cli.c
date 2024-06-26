#include "minishell.h"

static int	count_args(t_token *node)
{
	int	count;

	count = 0;
	while (node && node->type != PIPE)
	{
		node = node->next;
		count++;
	}
	return (count);
}

static char	**get_cli(t_token *token)
{
	int		i;
	int		count;
	char	**args;
	t_token	*temp;

	i = 0;
	count = count_args(token) + 1;
	args = malloc(sizeof(char *) * count);
	if (!args)
		exit_program(OUT_OF_MEMORY);
	while (i < count - 1)
	{
		args[i++] = token->str;
		token->str = NULL;
		temp = token->next;
		remove_token(token);
		token = temp;
	}
	get_control()->tokens = token;
	args[i] = NULL;
	return (args);
}

int	set_cli(t_token *tok, t_cli *cli)
{
	while (cli && tok)
	{
		if (tok->type > PIPE)
		{
			cli->type = tok->type;
			cli->args = get_cli(tok);
		}
		tok = get_control()->tokens;
		if (!tok)
			break ;
		if (tok->type == PIPE)
		{
			tok = tok->next;
			if (tok && tok->prev)
				remove_token(tok->prev);
			else
				remove_token(tok);
			cli = cli->next;
		}
	}
	return (1);
}

t_cli	*remove_cli(t_cli *cli)
{
	t_cli	*next;
	t_cli	*temp;

	if (!cli)
		return (NULL);
	temp = get_control()->commands;
	next = cli->next;
	while (temp && temp->next != cli)
		temp = temp->next;
	if (get_control()->commands == cli)
		get_control()->commands = next;
	else
		temp->next = next;
	if (cli->args)
		clear_pbox(cli->args);
	if (cli->fd[0] > 2)
		close(cli->fd[0]);
	if (cli->fd[1] > 2)
		close(cli->fd[1]);
	free(cli);
	return (next);
}
