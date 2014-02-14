/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_inter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrault <abrault@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/12 18:39:33 by abrault           #+#    #+#             */
/*   Updated: 2014/02/14 12:32:17 by abrault          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>
#include <stdio.h>

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

	a = carre(dir->x) + carre(dir->y) + carre(dir->z);
	b = 2 * (dir->x * (e->scene->x - o->x) + dir->y * (e->scene->y - o->y) +
	dir->z * (e->scene->z - o->z));
	c = carre(e->scene->x - o->x) + carre(e->scene->y - o->y) +
		carre(e->scene->z - o->z) - carre(o->scale);
	t = carre(b) - 4 * a * c;
	return (t);
}
