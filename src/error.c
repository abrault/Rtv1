/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrault <abrault@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/29 11:56:26 by abrault           #+#    #+#             */
/*   Updated: 2014/01/29 12:36:44 by abrault          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	display_error(int code)
{
	if (code == 2)
		ft_putstr("Can't malloc ...\n");
	else if (code == 3)
		ft_putstr("\n");
	else if (code == 4)
		ft_putstr("\n");
}
