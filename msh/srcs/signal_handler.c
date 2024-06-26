#include "minishell.h"

static void	sig_handler(int sig)
{
	t_ctrl	*ctrl;

	if (sig != SIGINT)
		return ;
	ctrl = get_control();
	ft_putstr_fd("\n", STDOUT_FILENO);
	ctrl->status = 130;
	rl_on_new_line();
	rl_replace_line("", STDIN_FILENO);
	rl_redisplay();
}

static void	non_interactive_mode(int sig)
{
	int		code;
	t_ctrl	*ctrl;

	code = 128 + sig;
	ctrl = get_control();
	if (sig == SIGINT)
		ctrl->status = code;
	if (sig == SIGQUIT)
		ctrl->status = code;
	if (sig == SIGPIPE)
		exit_program(code);
	ft_putstr_fd("\n", STDOUT_FILENO);
}

static void	here_docking(int sig)
{
	if (sig == SIGINT)
		exit_program(128 + sig);
}

void	set_signals(int mode)
{
	if (mode == ACTIVE)
	{
		signal(SIGINT, sig_handler);
		signal(SIGQUIT, SIG_IGN);
		signal(SIGPIPE, SIG_DFL);
	}
	if (mode == INACTIVE)
	{
		signal(SIGINT, non_interactive_mode);
		signal(SIGQUIT, non_interactive_mode);
		signal(SIGPIPE, non_interactive_mode);
	}
	if (mode == DEFAULT)
	{
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_DFL);
		signal(SIGPIPE, SIG_DFL);
	}
	if (mode == HEREDOC)
		signal(SIGINT, here_docking);
}
