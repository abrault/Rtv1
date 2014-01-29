/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrault <abrault@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 12:38:54 by abrault           #+#    #+#             */
/*   Updated: 2013/11/29 15:39:21 by abrault          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *destination, void *source, size_t num)
{
	char	*str_1;
	char	*str_2;
	size_t	i;

	i = 0;
	str_1 = destination;
	str_2 = source;
	while (i < num && str_1[i] != '\0')
	{
		str_1[i] = str_2[i];
		i++;
	}
	return (destination);
}
