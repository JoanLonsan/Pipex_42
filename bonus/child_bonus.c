/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcrescen <jcrescen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 12:09:01 by jcrescen          #+#    #+#             */
/*   Updated: 2023/04/05 13:15:33 by jcrescen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

char	*ft_get_cmd(char **paths, char *cmd)
{
	char	*tmp;
	char	*command;

	while (*paths)
	{
		tmp = ft_strjoin(*paths, "/");
		command = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(command, 0) == 0)
			return (command);
		free(command);
		paths++;
	}
	return (NULL);
}

void	ft_sub_dup2(int zero, int one)
{
	dup2(zero, 0);
	dup2(one, 1);
}

void	ft_child(t_ppxb p, char **argv, char **envp)
{
	p.pid = fork();
	if (!p.pid)
	{
		if (p.idx == 0)
			ft_sub_dup2(p.infile, p.pipe[1]);
		else if (p.idx == p.cmd_nmbs - 1)
			ft_sub_dup2(p.pipe[2 * p.idx - 2], p.outfile);
		else
			ft_sub_dup2(p.pipe[2 * p.idx - 2], p.pipe[2 * p.idx + 1]);
		ft_close_pipes(&p);
		p.cmd_args = ft_split(argv[2 + p.here_doc + p.idx], ' ');
		p.cmd = ft_get_cmd(p.cmd_paths, p.cmd_args[0]);
		if (!p.cmd)
		{
			ft_msg_pipe(p.cmd_args[0]);
			ft_child_free(&p);
			exit(1);
		}
		execve(p.cmd, p.cmd_args, envp);
	}
}
