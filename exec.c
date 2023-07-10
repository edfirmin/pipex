/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edfirmin <edfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 11:08:18 by edfirmin          #+#    #+#             */
/*   Updated: 2023/06/30 12:24:48 by edfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exec2(char *path, char **com, char **argv, int fd[2])
{
	pid_t	fils2;
	int		file_fd;
	int		i;

	i = 0;
	file_fd = open(argv[3], O_WRONLY | O_TRUNC);
	fils2 = fork();
	if (fils2 == -1)
		ft_exit(0);
	if (fils2 == 0)
	{
		close(fd[1]);
		dup2(fd[0], 0);
		close(fd[0]);
		dup2(file_fd, 1);
		close(file_fd);
		i = execve(path, com, NULL);
	}
	if (i == -1)
		ft_exit(2);
}

void	exec1(char *path, char **com, char **argv, int fd[2])
{
	pid_t	fils1;
	int		file_fd;
	int		i;

	i = 0;
	file_fd = open(argv[0], O_RDONLY);
	fils1 = fork();
	if (fils1 == -1)
		ft_exit(0);
	if (fils1 == 0)
	{
		dup2(file_fd, 0);
		close(fd[0]);
		dup2(fd[1], 1);
		close(fd[1]);
		close(file_fd);
		i = execve(path, com, NULL);
	}
	if (i == -1)
		ft_exit(2);
	exit(0);
}

void	exec(char **path, char **argv)
{
	pid_t	pid;
	int		fds[2];
	int		status;
	char	**av1;
	char	**av2;

	pipe(fds);
	av1 = ft_split(argv[1], ' ');
	av2 = ft_split(argv[2], ' ');
	pid = fork();
	if (pid == -1)
		ft_exit(0);
	if (pid == 0)
		exec1(path[0], av1, argv, fds);
	waitpid(pid, &status, 0);
	exec2(path[1], av2, argv, fds);
	tab_free(av1);
	tab_free(av2);
}
