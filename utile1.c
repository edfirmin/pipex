/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utile1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edfirmin <edfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 14:42:54 by edfirmin          #+#    #+#             */
/*   Updated: 2023/06/30 09:53:15 by edfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_exit(int n)
{
	ft_printf("Error\n");
	if (n == 0)
		return ;
	if (n == 1)
		ft_printf("You don't have the rights to the file !\n");
	if (n == 2)
		ft_printf("The commend does not exist !\n");
	if (n == 3)
		ft_printf("Non-existent file !\n");
	if (n == 4)
		ft_printf("Invalid arguments number !\n");
	if (n == 5)
		ft_printf("No path\n");
	exit(0);
}

char	*get_path1(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '/')
		i++;
	return (ft_strdup(&str[i]));
}

char	**get_path2(char *env)
{
	char	**tab;
	char	*str;
	int		j;

	j = 0;
	str = get_path1(env);
	tab = ft_split(str, ':');
	free(str);
	while (tab[j])
	{
		tab[j] = ft_strjoin2(tab[j], "/");
		j++;
	}
	return (tab);
}

char	*find_path(char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (ft_strstr(env[i], "PATH=") == 1)
			return (env[i]);
		i++;
	}
	ft_exit(5);
	return (NULL);
}
