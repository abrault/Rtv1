/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrault <abrault@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/29 12:50:22 by abrault           #+#    #+#             */
/*   Updated: 2014/02/14 17:45:22 by abrault          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>
#include <stdio.h>

int		draw_image(t_env *e)
{
	int			x;
	int			y;
	t_point		point;
	float		i;
	t_object	*ptr_object;

	y = 0;
	ptr_object = e->object;
	while (y < H_WIN)
	{
		x = 0;
		while (x < W_WIN)
		{
			while (e->object)
			{
				point.x = x;
				point.y = y;
				i = ray_tracing(e, &point);
				if (i >= -0.2)
				{
					point.red = i * e->object->r / 70;
					point.green = i * e->object->g / 70;
					point.blue = i * e->object->b / 70;
				}
				mlx_pixel_put_to_image(e, &point);
				x++;
				e->object = e->object->next_object;
			}
			e->object = ptr_object;
		}
		y++;
	}
	return (0);
}
