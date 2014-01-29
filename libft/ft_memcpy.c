/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrault <abrault@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 12:00:02 by abrault           #+#    #+#             */
/*   Updated: 2013/11/29 15:05:47 by abrault          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *destination, const void *source, size_t num)
{
	size_t		i;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	while (i < num)
	{
		str1 = (unsigned char*) destination + i;
		str2 = (unsigned char*) source + i;
		*str1 = *str2;
		i++;
	}
	return (destination);
}
