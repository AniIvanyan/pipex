/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aivanyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 18:29:04 by aivanyan          #+#    #+#             */
/*   Updated: 2022/10/29 13:22:12 by aivanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(int argc, char **argv, char **envp)
{
	int		pipefd[2];
	int		filefd[2];
	pid_t	child;
	int		i;
	
	i = 0;
	if (argc != 5)
	{
		write(1, "Invalid number of arguments", 28);
		return (EXIT_FAILURE);
	}
	filefd[0] = open(argv[1], O_WRONLY);
	filefd[1] = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (filefd[0] < 0 || filefd[1] < 0)
		exit(EXIT_FAILURE);
	if (pipe(pipefd) < 0)
		exit(EXIT_FAILURE);
	while (i < 2)
	{
		child = fork();
		if (child < 0)
			exit(EXIT_FAILURE);
		if (child == 0)
			process(pipefd[1 - i], filefd[i], argv[i + 2], 1 - i);
		close(pipefd[1 - i++]);
	}
	wait(NULL);
	wait(NULL);
}

void	process(int pipefd, int fd, char *cmd, int is_first)
{
	if (is_first)
		if (dup2(fd, STDIN_FILENO) < 0 || dup2(pipefd, STDOUT_FILENO) < 0)
			exit(EXIT_FAILURE);
	else
		if (dup2(pipefd, STDIN_FILENO < 0 || dup2(fd, STDOUT_FILENO < 0)))
			exit(EXIT_FAILURE);
	execute(cmd);			
}

execute(char *cmd)
{
	
}