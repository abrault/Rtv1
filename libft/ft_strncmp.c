/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrault <abrault@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 09:15:29 by abrault           #+#    #+#             */
/*   Updated: 2014/01/12 14:34:34 by abrault          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char * str1, const char * str2, size_t n)
{
	size_t	i;
	int	result;

	i = 0;
	result = 0;
	if (str1 == NULL && str2 == NULL)
		return (0);
	else if (str1 == NULL)
		return (0 - str2[0]);
	else if (str2 == NULL)
		return (str1[0]);
	while ((str1[i] != 0 && str2[i] != 0) && i < n)
	{
		result = str1[i] - str2[i];
		if (result != 0)
			return (result);
		i++;
	}
	if (str1[i] == '\0' && str2[i] != '\0')
		result = 0 - str2[i];
	else if (str1[i] != '\0' && str2[i] == '\0')
		result = str1[i];
	else if (str1[i] == '\0' && str2[i] == '\0')
		result = 0;
	return (result);
}
