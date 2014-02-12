/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrault <abrault@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/29 12:50:22 by abrault           #+#    #+#             */
/*   Updated: 2014/02/12 12:33:42 by abrault          ###   ########.fr       */
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

	y = 0;
	while (y < H_WIN)
	{
		x = 0;
		while (x < W_WIN)
		{
			point.x = x;
			point.y = y;
			i = ray_tracing(e, &point);
			if (i >= 0)
				point.red = 0;
			else
				point.red = 255;
			mlx_pixel_put_to_image(e, &point);
			x++;
		}
		y++;
	}
	return (0);
}
