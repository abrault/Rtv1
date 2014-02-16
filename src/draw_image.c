/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrault <abrault@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/29 12:50:22 by abrault           #+#    #+#             */
/*   Updated: 2014/02/16 09:57:18 by abrault          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

static int		work(t_env *e, t_point *point)
{
	float		dist;
	float		result;
	t_vector	*v;

	v = NULL;
	result = 1000000;
	while (e->object)
	{
		v = ray_tracing(e, point);
		if (v != NULL)
		{
			dist = sqrt(carre(v->x) + carre(v->y) + carre(v->z));
			if (result > dist)
			{
				result = dist;
				point->red = e->object->r;
				point->green = e->object->g;
				point->blue = e->object->b;
				mlx_pixel_put_to_image(e, point);
			}
		}
		e->object = e->object->next_object;
	}
	return (0);
}

int				draw_image(t_env *e)
{
	int			x;
	int			y;
	t_point		point;
	t_object	*ptr_object;

	y = 0;
	ptr_object = e->object;
	while (y < H_WIN)
	{
		x = 0;
		point.y = y;
		while (x < W_WIN)
		{
			point.x = x;
			work(e, &point);
			x++;
			e->object = ptr_object;
		}
		y++;
	}
	return (0);
}
