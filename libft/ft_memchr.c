/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrault <abrault@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 12:42:36 by abrault           #+#    #+#             */
/*   Updated: 2013/11/28 16:46:53 by abrault          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(void *ptr, int value, size_t num)
{
	char	*str;
	size_t	i;

	i = 0;
	while (i < num)
	{
		str = ptr + i;
		if (value == *str)
			return (ptr + i);
		i++;
	}
	return (NULL);
}
