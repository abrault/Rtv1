/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tracing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrault <abrault@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/29 18:20:49 by abrault           #+#    #+#             */
/*   Updated: 2014/02/16 17:42:46 by abrault          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>
#include <stdlib.h>
#include <math.h>

static t_vector	*get_vector_hg(t_env *e)
{
	t_vector	*pos_hg;
	t_vector	dir;
	t_vector	right_vec;

	dir.x = 0.0;
	dir.y = 0.0;
	dir.z = 1.0;
	right_vec.x = 1.0;
	right_vec.y = 0.0;
	right_vec.z = 0.0;
	pos_hg = malloc(sizeof(t_vector));
	pos_hg->x = e->scene->x + ((dir.x * V_DIST) + (0.0 * (V_HEIGHT / 2.0))) -
		(right_vec.x * (V_WIDTH / 2.0));
	pos_hg->y = e->scene->y + ((dir.y * V_DIST) + (1.0 * (V_HEIGHT / 2.0))) -
		(right_vec.y * (V_WIDTH / 2.0));
	pos_hg->z = e->scene->z + ((dir.z * V_DIST) + (0.0 * (V_HEIGHT / 2.0))) -
		(right_vec.z * (V_WIDTH / 2.0));
	return (pos_hg);
}

static t_vector	*get_vector_dir(t_env *e, t_vector *hg, t_point *p)
{
	t_vector	*dir;
	t_vector	d;
	t_vector	right_vec;

	d.x = 0.0;
	d.y = 0.0;
	d.z = 1.0;
	right_vec.x = 1.0;
	right_vec.y = 0.0;
	right_vec.z = 0.0;
	dir = malloc(sizeof(t_vector));
	dir->x = hg->x + right_vec.x * (V_WIDTH / W_WIN) * p->x - 0.0 *
		(V_HEIGHT / H_WIN) * p->y - e->scene->x;
	dir->y = hg->y + right_vec.y * (V_WIDTH / W_WIN) * p->x - 1.0 *
		(V_HEIGHT / H_WIN) * p->y - e->scene->y;
	dir->z = hg->z + right_vec.z * (V_WIDTH / W_WIN) * p->x - 0.0 *
		(V_HEIGHT / H_WIN) * p->y - e->scene->z;
	return (dir);
}

t_vector		*ray_tracing(t_env *e, t_point *point)
{
	t_vector	*vector_hg;
	t_vector	*vector_dir;
	float		n;

	vector_hg = get_vector_hg(e);
	vector_dir = get_vector_dir(e, vector_hg, point);
	n = sqrt(carre(vector_dir->x) + carre(vector_dir->y) +
			carre(vector_dir->z));
	vector_dir->x /= n;
	vector_dir->y /= n;
	vector_dir->z /= n;
	e->t = find_inter(e->scene, vector_dir, e->object);
	if (e->t < 0)
		return (NULL);
	free(vector_hg);
	vector_dir->x = e->scene->x + vector_dir->x * e->t;
	vector_dir->y = e->scene->y + vector_dir->y * e->t;
	vector_dir->z = e->scene->z + vector_dir->z * e->t;
	return (vector_dir);
}
