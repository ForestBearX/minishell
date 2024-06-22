#include "minishell.h"

int	has_var(char *str)
{
	while (*str)
	{
		if (*str == '$' && is_var(*(str + 1)))
			return (1);
		str++;
	}
	return (0);
}

void	free_pbox(char **pbox, int size)
{
	int		i;

	i = -1;
	while (++i < size)
		if (pbox[i])
			free(pbox[i]);
	null_pbox(pbox, size);
}

void	null_pbox(char **pbox, int size)
{
	int		i;

	i = -1;
	while (++i < size)
		pbox[i] = NULL;
}

char	*copy_str(char *input, int start, int len)
{
	char	*str;

	str = malloc(sizeof(char) * len);
	if (!str)
		exit_program(OUT_OF_MEMORY);
	ft_strlcpy(str, &input[start], len);
	return (str);
}

void	get_quote(char *input, int *i)
{
	char	quote;

	quote = input[(*i)++];
	while (input[*i] && input[*i] != quote)
		(*i)++;
}
