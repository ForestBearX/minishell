#include "minishell.h"

void	call_builtin(t_cli *cli)
{
	t_ctrl	*ctrl;
	char	*builtin;
	char	**args;

	if (!cli)
		return ;
	args = NULL;
	if (cli->args[1])
		args = &cli->args[1];
	builtin = cli->args[0];
	ctrl = get_control();
	if (!ft_strcmp(builtin, "cd"))
		ctrl->status = b_cd(args);
	else if (!ft_strcmp(builtin, "pwd"))
		ctrl->status = b_pwd();
	else if (!ft_strcmp(builtin, "echo"))
		ctrl->status = b_echo(args);
	else if (!ft_strcmp(builtin, "unset"))
		ctrl->status = b_unset(args, ctrl->env);
	else if (!ft_strcmp(builtin, "export"))
		ctrl->status = b_export(ctrl->env, args);
	else if (!ft_strcmp(builtin, "env"))
		ctrl->status = b_env(args, ctrl->env);
	else if (!ft_strcmp(builtin, "exit"))
		ctrl->status = b_exit(args);
}

int	print_builtin_errors(char *str, int error)
{
	ft_putstr_fd(str, STDERR_FILENO);
	return (error);
}
