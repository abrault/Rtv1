/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getTab2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrault <abrault@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/22 13:31:48 by abrault           #+#    #+#             */
/*   Updated: 2014/01/12 14:31:27 by abrault          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_getTab2(int ***tab, int height, int width)
{
	int	i;
	int	x;

	i = 0;
	**tab = malloc(sizeof(**tab) * height);
	while (i < height)
	{
		x = 0;
		*tab[i] = malloc(sizeof(**tab) * width);
		while (x < width)
		{
			*tab[i][x] = 0;
			x++;
		}
		i++;
	}
}
