/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tracing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrault <abrault@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/29 18:20:49 by abrault           #+#    #+#             */
/*   Updated: 2014/01/29 19:09:19 by abrault          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>
#include <math.h>

int		ray_tracing(t_env *e, t_point *point)
{
	(void)e;
	point->red = 0;
	point->green = 0;
	point->blue = 0;
	if (e->expose == 1)
		point->red = 255;
	else
		point->green = 255;
	return (0);
}
