/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_inter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrault <abrault@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/12 18:39:33 by abrault           #+#    #+#             */
/*   Updated: 2014/02/16 09:03:39 by abrault          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>
#include <math.h>

float	carre(float i)
{
	return (i * i);
}

int		find_inter(t_env *e, t_vector *dir, t_object *o)
{
	float	t;
	float	a;
	float	b;
	float	c;
	float	result[2];

	a = carre(dir->x) + carre(dir->y) + carre(dir->z);
	b = 2 * (dir->x * (e->scene->x - o->x) + dir->y * (e->scene->y - o->y) +
	dir->z * (e->scene->z - o->z));
	c = carre(e->scene->x - o->x) + carre(e->scene->y - o->y) +
		carre(e->scene->z - o->z) - carre(o->scale);
	t = carre(b) - 4 * a * c;
	if (t == 0)
		return (0);
	else if (t == -1)
		return (-1);
	result[0] = (-b - sqrt(t)) / 2 * a;
	result[1] = (-b + sqrt(t)) / 2 * a;
	if (result[0] > result[1])
		return (result[1]);
	return (result[0]);
}
