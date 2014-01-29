/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrault <abrault@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 09:16:10 by abrault           #+#    #+#             */
/*   Updated: 2014/01/12 14:42:40 by abrault          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str_1, const char *str_2, size_t n)
{
	size_t	i;
	int	j;
	int	mem;

	i = 0;
	j = 0;
	mem = 0;
	if (str_1 == NULL || str_2 == NULL || n == 0)
		return (NULL);
	while (str_1[i] != '\0' && i < n)
	{
		if (str_1[i] == str_2[j])
		{
			if (j == 0)
				mem = i;
			j++;
		}
		else
			j = 0;
		if (j == ft_strlen(str_2))
			return ((char*) str_1 + mem);
		i++;
	}
	return (NULL);
}
