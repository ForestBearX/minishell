#include "minishell.h"

void	prompt_user(const char *prompt)
{
	t_ctrl	*control;

	control = get_control();
	set_signals(ACTIVE);
	control->input = readline(prompt);
	if (!control->input)
		exit_program(0);
	add_history(control->input);
	if (!validate_input(control->input))
	{
		tokenization(control->input);
		if (executor_constructor(control->tokens))
			run_commands();
		clear_tokens(control->tokens);
		control->tokens = NULL;
		clear_cli(control->commands);
		control->commands = NULL;
	}
	free(control->input);
}
