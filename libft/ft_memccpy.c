/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrault <abrault@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 12:00:02 by abrault           #+#    #+#             */
/*   Updated: 2013/12/01 14:05:20 by abrault          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *destination, const void *source, int c, size_t num)
{
	char		*dest;
	const char	*src;
	char		code;

	dest = destination;
	src = source;
	while (num--)
	{
		code = *src++;
		*dest++ = code;
		if (code == c)
			return (dest);
	}
	return (NULL);
}
