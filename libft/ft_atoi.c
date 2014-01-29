/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrault <abrault@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 09:04:42 by abrault           #+#    #+#             */
/*   Updated: 2013/12/22 13:31:27 by abrault          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int		number;
	int		isNeg;
	int		i;

	number = 0;
	i = 0;
	isNeg = 0;
	while (i <= ft_strlen(str))
	{
		if (str[i] >= '0' && str[i] <= '9')
			number = str[i] - '0' + number * 10;
		else if (str[i] > '9' || (str[i] < '0' && i > 0))
			break ;
		else if (str[0] == '-' && i == 0)
			isNeg = 1;
		else if (str[0] == '+' && i == 0)
			;
		else
			break ;
		i++;
	}
	if (isNeg)
		number = 0 - number;
	return (number);
}
