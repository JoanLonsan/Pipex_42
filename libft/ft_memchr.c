/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcrescen <jcrescen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 13:45:34 by jcrescen          #+#    #+#             */
/*   Updated: 2023/04/03 13:45:35 by jcrescen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t len)
{
	char			*str_val;
	unsigned int	i;

	str_val = (char *)str;
	i = 0;
	while (i < len)
	{
		if (str_val[i] == c)
		{
			return ((void *)(str + i));
		}
		i++;
	}
	return (NULL);
}
