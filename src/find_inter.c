/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_inter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrault <abrault@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/12 18:39:33 by abrault           #+#    #+#             */
/*   Updated: 2014/02/16 17:35:32 by abrault          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>
#include <math.h>

float	carre(float i)
{
	return (i * i);
}

float	find_inter(t_scene *o, t_vector *dir, t_object *ob)
{
	float	t;
	float	a;
	float	b;
	float	c;
	float	result[2];

	a = carre(dir->x) + carre(dir->y) + carre(dir->z);
	b = 2.0 * (dir->x * (o->x - ob->x) + dir->y * (o->y - ob->y) + dir->z *
			(o->z - ob->z));
	c = (carre(o->x - ob->x) + carre(o->y - ob->y) + carre(o->z - ob->z)) -
		carre(ob->scale);
	t = carre(b) - 4.0 * a * c;
	if (t < 0)
		return (-1);
	else if (t == 0)
		return (-b / (2 * a));
	result[0] = (-b - sqrt(t)) / (2.0 * a);
	result[1] = (-b + sqrt(t)) / (2.0 * a);
	if (result[0] > result[1])
		return (result[1]);
	return (result[0]);
}
