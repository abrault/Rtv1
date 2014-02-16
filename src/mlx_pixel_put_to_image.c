/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_pixel_put_to_image.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrault <abrault@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/16 21:09:52 by abrault           #+#    #+#             */
/*   Updated: 2014/02/16 21:09:54 by abrault          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void			mlx_pixel_put_to_image(t_env *e, t_point *point)
{
	int		i;
	int		x;
	int		y;

	i = 0;
	x = point->x * e->img->bpp / 8;
	y = point->y * e->img->size_line;
	e->img->data[x + i++ + y] = mlx_get_color_value(e->mlx, point->blue);
	e->img->data[x + i++ + y] = mlx_get_color_value(e->mlx, point->green);
	e->img->data[x + i++ + y] = mlx_get_color_value(e->mlx, point->red);
}
