/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrault <abrault@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 12:44:12 by abrault           #+#    #+#             */
/*   Updated: 2013/11/28 16:47:04 by abrault          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	size_t		i;
	const char	*p1;
	const char	*p2;

	i = 0;
	while (i < num)
	{
		p1 = ptr1 + i;
		p2 = ptr2 + i;
		if (*p1 != *p2)
			return (*p1 - *p2);
		i++;
	}
	return (0);
}
