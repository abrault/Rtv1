/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrault <abrault@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/29 12:50:22 by abrault           #+#    #+#             */
/*   Updated: 2014/01/29 19:09:16 by abrault          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

int		draw_image(t_env *e)
{
	int			x;
	int			y;
	t_point		point;

	y = 0;
	while (y < H_WIN)
	{
		x = 0;
		while (x < W_WIN)
		{
			ray_tracing(e, &point);
			point.x = x;
			point.y = y;
			mlx_pixel_put_to_image(e, &point);
			x++;
		}
		y++;
	}
	return (0);
}
