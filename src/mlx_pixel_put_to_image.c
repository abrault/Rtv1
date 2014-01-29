/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_put_pixel_to_image.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrault <abrault@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/29 11:33:49 by abrault           #+#    #+#             */
/*   Updated: 2014/01/29 12:13:32 by abrault          ###   ########.fr       */
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
