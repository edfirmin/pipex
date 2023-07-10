/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edfirmin <edfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 11:24:49 by edfirmin          #+#    #+#             */
/*   Updated: 2023/07/03 10:49:10 by edfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	check_file(char *file, int n)
{
	int	i;

	if (n == 0)
	{
		if (access(file, F_OK) == -1)
			ft_exit(3);
		i = access(file, R_OK);
	}
	if (n == 3)
	{
		if (access(file, F_OK) == -1)
		{
			i = open(file, O_CREAT, 0000666);
			close(i);
		}
		i = access(file, W_OK);
	}
	if (i == -1)
		ft_exit(1);
}

char	*absolute(char	**str)
{
	int		j;
	char	*sstr;

	j = 0;
	j = access(str[0], X_OK);
	if (j == -1)
		ft_exit(2);
	sstr = ft_strdup(str[0]);
	tab_free(str);
	return (sstr);
}

char	*check_com(char **com, char **env)
{
	int		i;
	int		j;
	char	*str;

	i = -1;
	j = 0;
	if (ft_strstr(com[0], "/") == 1)
		return (absolute(com));
	while (env[++i])
	{
		str = ft_strjoin(env[i], com[0]);
		j = access(str, X_OK);
		if (j == -1 && !env[i + 1])
		{
			tab_free(com);
			ft_exit(2);
		}
		if (j != -1)
		{
			tab_free(com);
			return (str);
		}
		free(str);
	}
	return (NULL);
}

char	**check_arg(char **str, char **env)
{
	char	**tab;
	char	**path;

	path = malloc(2 * sizeof(char *));
	check_file(str[0], 0);
	check_file(str[3], 3);
	tab = ft_split(str[1], ' ');
	path[0] = check_com(tab, env);
	tab = ft_split(str[2], ' ');
	path[1] = check_com(tab, env);
	tab_free(env);
	return (path);
}
