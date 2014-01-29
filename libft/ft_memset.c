/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrault <abrault@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 15:11:38 by abrault           #+#    #+#             */
/*   Updated: 2013/12/01 14:18:35 by abrault          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int charac, int num)
{
	int	i;
	char	*str;

	i = 0;
	while (i < num && str[i] != '\0')
	{
		str = ptr + i;
		*str = charac;
		i++;
	}
	return (ptr);
}
