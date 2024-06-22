#include "minishell.h"

int	b_pwd(void)
{
	char	current_path[PATH_MAX];

	if (!getcwd(current_path, sizeof(current_path)))
		exit_program(-1);
	ft_putstr_fd(current_path, STDOUT_FILENO);
	ft_putstr_fd("\n", STDOUT_FILENO);
	return (0);
}
