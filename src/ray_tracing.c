/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tracing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrault <abrault@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/29 18:20:49 by abrault           #+#    #+#             */
/*   Updated: 2014/02/16 09:04:44 by abrault          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>
#include <stdlib.h>
#include <math.h>

static t_vector	*get_vector_u(t_env *e)
{
	t_vector	*vector_u;

	vector_u = malloc(sizeof(t_vector));
	vector_u->x = 0 - e->scene->x;
	vector_u->y = 0 - e->scene->y;
	vector_u->z = 0 - e->scene->z;
	return (vector_u);
}

static t_vector	*scalaire(t_vector *u, t_vector *h)
{
	t_vector	*d;

	d = malloc(sizeof(t_vector));
	d->x = u->y * h->z - u->z * h->y;
	d->y = u->z * h->x - u->x * h->z;
	d->z = u->x * h->y - u->y * h->x;
	return (d);
}

static t_vector	*get_vector_hg(t_env *e, t_vector *u, t_vector *d, t_vector *h)
{
	t_vector	*pos_hg;
	float		dist;
	float		width;
	float		height;

	dist = 1;
	width = 0.35;
	height = 0.5;
	pos_hg = malloc(sizeof(t_vector));
	pos_hg->x = e->scene->x + dist * u->x + (height / 2) * h->x - (width / 2)
		* d->x;
	pos_hg->y = e->scene->y + dist * u->y + (height / 2) * h->y - (width / 2)
		* d->y;
	pos_hg->z = e->scene->z + dist * u->z + (height / 2) * h->z - (width / 2)
		* d->z;
	return (pos_hg);
}

static t_vector	*get_vector_dir(t_env *e, t_vector *hg, t_vector *d, t_point *p)
{
	t_vector	*dir;
	float		width;
	float		height;

	width = 0.35;
	height = 0.5;
	dir = malloc(sizeof(t_vector));
	dir->x = (hg->x - e->scene->x) + d->x * width / W_WIN * p->x - 0 * height
		/ H_WIN * p->y;
	dir->y = (hg->y - e->scene->y) + d->y * width / W_WIN * p->x - 1 * height
		/ H_WIN * p->y;
	dir->z = (hg->z - e->scene->z) + d->z * width / W_WIN * p->x - 0 * height
		/ H_WIN * p->y;
	return (dir);
}

t_vector		*ray_tracing(t_env *e, t_point *point)
{
	t_vector	*vector_u;
	t_vector	*vector_d;
	t_vector	*vector_h;
	t_vector	*vector_hg;
	t_vector	*vector_dir;

	vector_u = get_vector_u(e);
	vector_h = malloc(sizeof(t_vector));
	vector_h->x = 0;
	vector_h->y = 1;
	vector_h->z = 0;
	vector_d = scalaire(vector_u, vector_h);
	vector_hg = get_vector_hg(e, vector_u, vector_d, vector_h);
	vector_dir = get_vector_dir(e, vector_hg, vector_d, point);
	if ((e->t = find_inter(e, vector_dir, e->object)) == -1)
		return (NULL);
	free(vector_u);
	free(vector_d);
	free(vector_h);
	free(vector_hg);
	vector_dir->x = e->scene->x + vector_dir->x * e->t;
	vector_dir->y = e->scene->y + vector_dir->y * e->t;
	vector_dir->z = e->scene->z + vector_dir->z * e->t;
	return (vector_dir);
}
