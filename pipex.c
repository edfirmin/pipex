/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edfirmin <edfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 09:36:08 by edfirmin          #+#    #+#             */
/*   Updated: 2023/06/30 12:30:23 by edfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **env)
{
	char	**tab;
	char	**path;

	tab = get_path2(find_path(env));
	if (argc == 5)
	{
		path = check_arg(&argv[1], tab);
		exec(path, &argv[1]);
	}
	else
		ft_exit(4);
}
