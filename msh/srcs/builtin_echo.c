#include "minishell.h"

static void	print_args(char **args)
{
	while (*args)
	{
		ft_putstr_fd(*args++, STDOUT_FILENO);
		if (*args)
			ft_putstr_fd(" ", STDOUT_FILENO);
	}
}

static int	is_flag(char *flag)
{
	int	i;

	i = 0;
	if (flag[i] == '-')
		i++;
	else
		return (0);
	while (flag[i] == 'n')
		i++;
	if (!flag[i] && i > 1)
		return (1);
	return (0);
}

int	b_echo(char **args)
{
	if (!args)
		ft_putstr_fd("\n", STDOUT_FILENO);
	else if (is_flag(*args))
		print_args(++args);
	else
	{
		print_args(args);
		ft_putstr_fd("\n", STDOUT_FILENO);
	}
	return (0);
}
