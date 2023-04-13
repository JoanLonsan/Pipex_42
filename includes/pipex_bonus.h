/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipexbonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcrescen <jcrescen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 12:08:47 by jcrescen          #+#    #+#             */
/*   Updated: 2023/04/05 13:00:29 by jcrescen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <string.h>
# include <stdio.h>
# include "../libft/libft.h"

# define ERR_INFILE "Infile"
# define ERR_OUTFILE "Outfile"
# define ERR_INPUT "Invalid number of arguments.\n"
# define ERR_PIPE "Pipe"
# define ERR_ENVP "Environment"
# define ERR_CMD "Command not found: "
# define ERR_HEREDOC "here_doc"

typedef struct s_ppxb
{
	int		infile;
	int		outfile;
	char	*env_path;
	char	**cmd_paths;
	char	*cmd;
	char	**cmd_args;
	int		here_doc;
	pid_t	pid;
	int		cmd_nmbs;
	int		pipe_nmbs;
	int		*pipe;
	int		idx;
}t_ppxb;

void	ft_parent_free(t_ppxb *pipex);
void	ft_child_free(t_ppxb *pipex);
void	ft_pipe_free(t_ppxb *pipex);

void	ft_close_pipes(t_ppxb *pipex);
void	ft_child(t_ppxb pipex, char **argv, char **envp);
char	*ft_find_path(char **envp);
void	ft_get_infile(char **argv, t_ppxb *pipex);
void	ft_get_outfile(char *argv, t_ppxb *pipex);
int		ft_args_in(char *arg, t_ppxb *pipex);
void	ft_here_doc(char *argv, t_ppxb *pipex);
void	ft_msg_error(char *err);
void	ft_msg_pipe(char *arg);
int		ft_msg(char *err);

#endif
