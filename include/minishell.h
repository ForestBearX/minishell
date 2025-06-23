/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikkhach <mikkhach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 15:09:05 by mikkhach          #+#    #+#             */
/*   Updated: 2025/02/02 15:59:01 by mikkhach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# define MAX_PATH 4096

# include "./libft.h"
# include <stdio.h> // Printf
# include <stdlib.h> // Malloc, Free, exit
# include <fcntl.h> // Open
# include <unistd.h> // read, execve, fork, pipe, getcwd
# include <sys/wait.h> // waitpid
# include <signal.h> // signal
# include <sys/types.h>
# include <dirent.h>
# include <stdio.h>
# include <errno.h> // errno
# include <sys/stat.h> //S_ISDIR
# include <readline/readline.h> // Readline
# include <readline/history.h> // History

# define OLD_PWD "OLDPWD"
# define PWD "PWD"

# define STDOUT	STDOUT_FILENO
# define STDIN	STDIN_FILENO
# define STDERR	STDERR_FILENO

# define OR		1
# define AND	2
# define PIPE	3

# define CMD_NOT_FOUND 127
# define CMD_NOT_EXEC 126

// Color prompt
# define GREEN "\001\033[0;92m\002"
# define DEFAULT "\001\033[0;39m\002"
# define YELLOW "\001\033[0;93m\002"

typedef struct s_io
{
	int		fd_in;
	int		fd_out;
	int		std_in_bkp;
	int		std_out_bkp;
	char	*in_file;
	char	*out_file;
	char	*heredoc_delimiter;
	bool	error;
	int		cmd_index;

}	t_io;

typedef struct s_data
{
	char		*user_input;
	char		**env;
	char		*work_dir;
	char		*old_work_dir;
}	t_data;

typedef struct s_cmd
{
	char	*path;
	char	**args;
	char	**redirections;
}	t_cmd;

typedef struct s_pipe
{
	int	*fd;
}	t_pipe;

typedef struct s_commands
{
	pid_t			*pid;
	int				num_cmds;
	int				num_exec;
	char			**cmds;
	char			**paths;
	int				*operators;
	int				exit_value;
	t_pipe			*pipe;
	t_io			*io;
	t_cmd			*cmd;
}	t_commands;

typedef struct s_index_data
{
	size_t	i;
	size_t	malloc_size;
	size_t	j;
}	t_index_data;

typedef struct s_temp_index
{
	size_t	i;
	size_t	o;
	size_t	j;
}	t_temp_index;

typedef struct s_num_parenthesis
{
	int	first_p;
	int	last_p;
}	t_num_parenthesis;

extern int	g_status_code;

int		init(int argc, char **argv, char **envp);

bool	init_structure(t_data *data, char **envp);

void	init_io(t_commands *cmds);

void	init_cmds(t_data *data, t_commands *cmds);

void	init_cmd(t_data *data, t_commands *cmds, int num_cmd);

void	init_single_cmd(t_data *data, t_commands *cmds, int num_cmd);

char	*trim_user_imput(char *user_input);

bool	valid_args(int argc, char **argv);

bool	just_space_string(char *str);

void	exit_shell(t_data *data, int status_code);

void	signals_wait_cmd(void);

void	signals_run_cmd(void);

char	*get_prompt(t_data *data);

void	redirect_io(t_io *io, int index_cmd);

void	restore_io(t_io *io);

bool	check_in_out_file(t_io *io, t_commands *cmds, bool free);

int		rd_output_handler(t_commands *cmds, char *red, bool trunc);

void	redirection_handler(t_commands *cmds, int j);

bool	is_redirection_command(t_commands *cmds, int i);

int		rd_input_handler(t_commands *cmds, char *file);

bool	remove_old_file_ref(t_io *io, bool in_file);

void	rd_heredoc(t_commands *cmds, char *red);

bool	is_builtin(char *argv);

bool	is_builtin_without_output(t_commands *cmds);

int		call_builtin(t_data *data, t_commands *cmds, int num_cmd);

int		cmd_echo(t_commands *cmds, int num_cmd);

int		cmd_exit(t_data *data, t_commands *cmds, int num_cmd);

int		cmd_pwd(void);

int		cmd_env(t_data *data, t_commands *cmds, int num_cmd);

int		cmd_cd(t_data *data, t_commands *cmds, int n);

int		cmd_unset(t_data *data, t_commands *cmds, int num_cmd);

bool	is_valid_var_name(char *name);

void	set_pipe_fds(t_commands *cmds, int index);

void	close_pipe_fds(t_commands *cmds);

void	close_exec_pipe_fds(t_commands *cmds);

void	debug_structs(t_commands *cmds, bool show_path);

void	free_ptr(void *ptr);

void	close_fds(t_commands *cmds, bool reset_io);

void	free_io(t_io *io);

void	free_pipes(t_commands *cmds);

void	free_data(t_data *data, bool exit_shell);

char	**split_args(char *command);

char	*join_strs(char *str, char *add);

void	remove_quotes(char *str);

void	free_array_str(char **arr_str);

void	free_cmds(t_commands *cmds);

int		error_msg_cmd(char *cmd, char *detail, char *msg, int status_code);

int		exec_handler(t_data *data, t_commands *cmds);

void	exec_builtin_without_output(t_commands *cmds, t_data *data);

bool	input_is_dir(char *cmd);

int		validate_cmd_not_found(t_data *data, char *cmd);

void	free_exit_cmd(t_data *data, t_commands *cmds, int status_code);

int		exec_child(t_data *data, t_commands *cmds, int num_cmd);

void	verify_operators(t_data *data, t_commands *cmds, int num_cmd);

int		execute_cmd(t_data *data, t_commands *cmds, int num_cmd);

char	*get_env_var_value(char **env, char *var);

int		get_env_var_index(char **env, char *var);

int		env_var_count(char **envp);

bool	set_env_var(t_data *data, char *key, char *value);

void	env_var_remove(t_data *data, int index);

int		cmd_export(t_data *data, t_commands *cmds, int num_cmd);

char	**env_var_realloc(t_data *data, int size);

char	**lexer(char const *s, t_commands *cmds);

void	putchar_lexer(char const *s, char **str, size_t countc);

void	lexer_errors(t_index_data *i_data, const char *s, t_commands *cmds);

void	lexer_parenthesis(const char *s, t_commands *cmds);

void	quotes_error(t_index_data *i_data, const char *s, t_commands *cmds);

void	lexer_redirections(const char *s, t_commands *cmds);

void	lexer_operators(const char *s, t_commands *cmds);

char	*get_cmd_path(t_commands *cmds, int index);

char	**parser(char *s);

void	putchar_parser(char *s, char **str, size_t countc);

char	*handle_env(t_index_data *i_data, char *s, t_data *data);

void	find_dollar_sign(t_data *data, t_commands *cmds, int n);

char	**handle_redirection(char *s);

void	putchar_redirection(char *s, char **str, size_t countc);

char	*rm_redirection(char *s);

void	copy_cmd(char *s, char *new_str);

void	find_export_cmd(t_commands *cmds, int num_cmd);

char	**rm_spaces(char const *s);

void	putchar_split(char const *s, char **str, size_t countc);

#endif
