/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrault <abrault@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/29 12:50:22 by abrault           #+#    #+#             */
/*   Updated: 2014/02/16 21:29:29 by abrault          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>
#include <math.h>
#include <stdlib.h>

static int		work(t_env *e, t_point *point)
{
	float		result;
	t_vector	*v;

	result = 1000000;
	while (e->object)
	{
		v = NULL;
		v = ray_tracing(e, point);
		if (v != NULL)
		{
			if (result > e->t)
			{
				result = e->t;
				point->red = e->object->r / (e->t / 6);
				point->green = e->object->g / (e->t / 6);
				point->blue = e->object->b / (e->t / 6);
				mlx_pixel_put_to_image(e, point);
			}
			free(v);
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
	float		i;

	y = 0;
	i = 0;
	ptr_object = e->object;
	while (y < H_WIN)
	{
		x = 0;
		point.y = y;
		while (x < W_WIN)
		{
			point.x = x;
			work(e, &point);
			mlx_pixel_put(e->mlx, e->win, x, y, 0xFF0000 + i / 4);
			x++;
			e->object = ptr_object;
		}
		i++;
		y++;
	}
	return (0);
}
