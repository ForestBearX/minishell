#include "minishell.h"

int	is_bracket(char c)
{
	return (c == '>' || c == '<');
}

int	is_pipe(char c)
{
	return (c == '|');
}

int	print_error(char *msg, char *refstr, char refchar)
{
	ft_putstr_fd("msh: ", STDERR_FILENO);
	ft_putstr_fd(msg, STDERR_FILENO);
	if (refstr)
		ft_putstr_fd(refstr, STDERR_FILENO);
	if (refchar)
		ft_putchar_fd(refchar, STDERR_FILENO);
	if (refstr || refchar)
		ft_putstr_fd("'", STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
	get_control()->status = 2;
	return (1);
}
