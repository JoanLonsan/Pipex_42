/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcrescen <jcrescen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 12:06:49 by jcrescen          #+#    #+#             */
/*   Updated: 2023/04/05 12:06:50 by jcrescen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	ft_msg(char *err)
{
	write(2, err, ft_strlen(err));
	return (1);
}

void	ft_msg_error(char *err)
{
	perror(err);
	exit (1);
}
