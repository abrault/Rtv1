/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tracing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrault <abrault@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/29 18:20:49 by abrault           #+#    #+#             */
/*   Updated: 2014/02/05 17:12:19 by abrault          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>
#include <stdlib.h>
#include <math.h>

int				find_sphere(t_env *e, float *dir, int x, int y)
{
	float	d;
	(void)e;
	(void)dir;

	d = 1 + 2 * (x / W_WIN - 0.5) + 2 * (y / H_WIN - 0.5);
	d = d / ((d < 0) ? -d : d);
	return (d);
}

int				find_cylindre(t_env *e, float *dir)
{
	(void)e;
	(void)dir;
	return (0);
}

static float	*get_dir(t_env *e, int z, int y)
{
	float	*vector;

	vector = malloc(sizeof(char) * 3);
	(void)z;
	(void)y;
	(void)e;
	return (vector);
}

static int		find_inter(t_env *e, float *dir, int x, int y)
{
	int		ret;

	ret = 0;
	if (e->object->type == 1)
		ret = find_sphere(e, dir, x, y);
	else if (e->object->type == 2)
		ret = find_cylindre(e, dir);
	return (ret);
}

int				ray_tracing(t_env *e, t_point *point, int x, int y)
{
	float		*dir;
	t_object	*ptr_obj;

	dir = get_dir(e, x, y);
	ptr_obj = e->object;
	while (e->object)
	{
		if (find_inter(e, dir, x, y))
			point->red = 255;
		else
			point->red = 0;
		e->object = e->object->next_object;
	}
	point->green = 0;
	point->blue = 0;
	return (0);
}
