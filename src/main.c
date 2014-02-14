/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrault <abrault@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/29 11:52:22 by abrault           #+#    #+#             */
/*   Updated: 2014/02/14 12:32:14 by abrault          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>
#include <unistd.h>
#include <libft.h>

int		main(int ac, char **av)
{
	t_env	*e;

	e = NULL;
	if (ac != 2)
		ft_putstr("RTv1 usage: /RTv1 <map>\n");
	else
	{
		e = ini_env(e);
		ini_scene_and_object(e, av[1]);

		e->scene->x = -2;
		e->scene->y = 0;
		e->scene->z = 0;

		mlx_expose_hook(e->win, &expose_hook, e);
		mlx_hook(e->win, KeyPress, KeyRelease, &key_hook, e);
		mlx_loop_hook(e->mlx, loop_hook, e);
		mlx_loop(e->mlx);
	}
	return (0);
}
