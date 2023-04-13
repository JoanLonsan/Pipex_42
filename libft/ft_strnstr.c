/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcrescen <jcrescen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 13:47:02 by jcrescen          #+#    #+#             */
/*   Updated: 2023/04/03 13:47:02 by jcrescen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str,
	const char *sub_str, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!sub_str[j])
		return ((char *)(str));
	while (str[i] && sub_str[j] && len)
	{
		if (str[i] == sub_str[j])
			j++;
		else if (j)
		{
			j = 0;
			continue ;
		}
		i++;
		len--;
	}
	if (!sub_str[j])
		return ((char *)(str + i - j));
	return (0);
}
