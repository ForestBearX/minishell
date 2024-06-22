#include "minishell.h"

int	b_unset(char **args, t_env *env)
{
	if (!args)
		return (0);
	while (*args)
	{
		remove_var(*args, env);
		args++;
	}
	return (0);
}
