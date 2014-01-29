/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrault <abrault@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 09:14:07 by abrault           #+#    #+#             */
/*   Updated: 2014/01/12 14:33:56 by abrault          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_strdup(const char *str)
{
	int		lenght;
	char	*new_string;
	int		i;

	if (str == NULL)
		return (NULL);
	i = 0;
	lenght = ft_strlen(str);
	new_string = malloc(sizeof(char) * lenght);
	while (i < lenght)
	{
		new_string[i] = str[i];
		i++;
	}
	return (new_string);
}
