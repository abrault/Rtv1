/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrault <abrault@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 09:11:49 by abrault           #+#    #+#             */
/*   Updated: 2014/01/12 14:33:18 by abrault          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_strcmp(const char * str1, const char * str2 )
{
	int		i;
	int		result;

	i = 0;
	result = 0;
	while (str1[i] != '\0' && str2[i] != '\0')
	{
		result = str1[i] - str2[i];
		if (result != 0)
			return (result);
		i++;
	}
	if (str1[i] == '\0' && str2[i] != '\0')
		return (0 - str2[i]);
	else if (str1[i] != '\0' && str2[i] == '\0')
		return (str1[i]);
	return (0);
}
