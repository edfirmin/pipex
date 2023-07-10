/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edfirmin <edfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 09:34:39 by edfirmin          #+#    #+#             */
/*   Updated: 2023/07/03 10:49:15 by edfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "lib/libft.h"
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>

void	ft_exit(int n);
char	*get_path1(char *str);
char	**get_path2(char *env);
char	**check_arg(char **str, char **env);
char	*check_com(char **com, char **env);
void	check_file(char *file, int n);
void	exec(char **path, char **argv);
char	*find_path(char **env);
char	*absolute(char	**str);
#endif
