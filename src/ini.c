/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ini.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrault <abrault@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/29 11:53:27 by abrault           #+#    #+#             */
/*   Updated: 2014/02/13 17:46:46 by abrault          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>
#include <stdlib.h>

t_env	*ini_env(t_env *e)
{
	e = malloc(sizeof(t_env));
	e->mlx = malloc(sizeof(void*));
	e->mlx = mlx_init();
	e->win = malloc(sizeof(void*));
	e->win = mlx_new_window(e->mlx, W_WIN, H_WIN, "RTv1");
	e->img = malloc(sizeof(t_img));
	e->img = mlx_new_image(e->mlx, W_WIN, H_WIN);
	e->img->data = mlx_get_data_addr(e->img, &(e->img->bpp),
			&(e->img->size_line), &(e->img->endian));
	e->expose = 0;
	e->scene = malloc(sizeof(t_scene));
	e->object = malloc(sizeof(t_object));
	e->object = NULL;
	return (e);
}
