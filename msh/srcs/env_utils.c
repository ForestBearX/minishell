#include "minishell.h"

static int	count_list(t_env *list)
{
	int	i;

	i = 0;
	while (list)
	{
		list = list->next;
		i++;
	}
	return (i);
}

static char	*copy_to_env(char *key, char *value)
{
	char	*str;
	int		key_len;
	int		val_len;

	val_len = 0;
	if (value)
		val_len = ft_strlen(value) + 1;
	key_len = ft_strlen(key) + 1;
	str = malloc(sizeof(char) * (key_len + val_len));
	if (!str)
		return (NULL);
	ft_strlcpy(str, key, key_len);
	if (value)
	{
		ft_strlcpy(str + key_len, value, val_len);
		str[key_len - 1] = '=';
	}
	return (str);
}

static char	*copy_to_export(char *key, char *value)
{
	char	*str;
	int		key_len;
	int		val_len;

	val_len = 0;
	if (value)
		val_len = ft_strlen(value) + 3;
	key_len = ft_strlen(key) + 1;
	str = malloc(sizeof(char) * (key_len + val_len));
	if (!str)
		return (NULL);
	ft_strlcpy(str, key, key_len);
	if (value)
	{
		str[key_len - 1] = '=';
		str[key_len] = '"';
		ft_strlcpy(str + key_len + 1, value, val_len);
		str[key_len + val_len - 2] = '"';
		str[key_len + val_len - 1] = '\0';
	}
	return (str);
}

char	**stringify_env(t_env *list, int flag)
{
	char	**env;
	int		i;
	int		len;

	i = 0;
	len = count_list(list);
	env = malloc(sizeof(char *) * (len + 1));
	if (!env)
		return (NULL);
	while (i < len)
	{
		if (flag)
			env[i] = copy_to_export(list->key, list->value);
		else
			env[i] = copy_to_env(list->key, list->value);
		if (!env[i++])
			return (NULL);
		list = list->next;
	}
	env[i] = NULL;
	return (env);
}
