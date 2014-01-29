/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrault <abrault@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 09:11:26 by abrault           #+#    #+#             */
/*   Updated: 2014/01/12 14:31:56 by abrault          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c_ascii)
{
	char	n;
	int	i;

	if (str == NULL)
		return (NULL);
	i = 0;
	n = c_ascii;
	while (str[i] != '\0')
	{
		if (str[i] == n)
			return ((char*) str + i);
		i++;
	}
	if (c_ascii == 0)
		return ((char *) str + i);
	return (NULL);
}
