/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcrescen <jcrescen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 12:09:37 by jcrescen          #+#    #+#             */
/*   Updated: 2023/04/05 13:13:04 by jcrescen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

void	ft_create_pipes(t_ppxb *pipex)
{
	int	i;

	i = 0;
	while (i < pipex->cmd_nmbs - 1)
	{
		if (pipe(pipex->pipe + 2 * i) < 0)
			ft_parent_free(pipex);
		i++;
	}
}

void	ft_close_pipes(t_ppxb *pipex)
{
	int	i;

	i = 0;
	while (i < (pipex->pipe_nmbs))
	{
		close(pipex->pipe[i]);
		i++;
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_ppxb	pipex;

	if (argc < ft_args_in(argv[1], &pipex))
		return (ft_msg(ERR_INPUT));
	ft_get_infile(argv, &pipex);
	ft_get_outfile(argv[argc - 1], &pipex);
	pipex.cmd_nmbs = argc - 3 - pipex.here_doc;
	pipex.pipe_nmbs = 2 * (pipex.cmd_nmbs - 1);
	pipex.pipe = (int *)malloc(sizeof(int) * pipex.pipe_nmbs);
	if (!pipex.pipe)
		ft_msg_error(ERR_PIPE);
	pipex.env_path = ft_find_path(envp);
	pipex.cmd_paths = ft_split(pipex.env_path, ':');
	if (!pipex.cmd_paths)
		ft_pipe_free(&pipex);
	ft_create_pipes(&pipex);
	pipex.idx = -1;
	while (++(pipex.idx) < pipex.cmd_nmbs)
		ft_child(pipex, argv, envp);
	ft_close_pipes(&pipex);
	waitpid(-1, NULL, 0);
	ft_parent_free(&pipex);
	return (0);
}
