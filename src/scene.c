/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrault <abrault@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/29 13:45:38 by abrault           #+#    #+#             */
/*   Updated: 2014/02/16 19:58:10 by abrault          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <rt.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int				ini_scene_and_object(t_env *e, char *str)
{
	char		*line;
	int			fd;

	line = NULL;
	if ((fd = open(str, O_RDONLY)) == -1)
	{
		ft_putstr("Incorrect file ...");
		return (0);
	}
	while (get_next_line(fd, &line))
	{
		if (line[0] != '#' || line[0] == '\0')
		{
			if (ft_strstr(line, "scene"))
				e->scene = get_scene(fd);
			else if (ft_strstr(line, "object"))
				e->object = get_object(e, fd);
		}
	}
	close(fd);
	return (1);
}

t_scene			*get_scene(int fd)
{
	t_scene		*scene;
	char		*line;

	scene = malloc(sizeof(t_scene));
	get_next_line(fd, &line);
	scene->x = ft_atoi(ft_strtok(line, ':'));
	scene->y = ft_atoi(ft_strtok(NULL, ':'));
	scene->z = ft_atoi(ft_strtok(NULL, ':'));
	free(line);
	return (scene);
}

static t_vector	*get_vector_n(int fd)
{
	char		*line;
	t_vector	*v;

	v = malloc(sizeof(t_vector));
	get_next_line(fd, &line);
	v->x = ft_atoi(ft_strtok(line, ':'));
	v->y = ft_atoi(ft_strtok(NULL, ':'));
	v->z = ft_atoi(ft_strtok(NULL, ':'));
	free(line);
	return (v);
}

t_object		*get_object(t_env *e, int fd)
{
	t_object	*object;
	char		*line;

	object = malloc(sizeof(t_object));
	get_next_line(fd, &line);
	object->type = get_type(line);
	free(line);
	get_next_line(fd, &line);
	object->x = ft_atoi(ft_strtok(line, ':'));
	object->y = ft_atoi(ft_strtok(NULL, ':'));
	object->z = ft_atoi(ft_strtok(NULL, ':'));
	free(line);
	get_next_line(fd, &line);
	object->scale = ft_atoi(line);
	free(line);
	get_next_line(fd, &line);
	object->r = ft_atoi(ft_strtok(line, ':'));
	object->g = ft_atoi(ft_strtok(NULL, ':'));
	object->b = ft_atoi(ft_strtok(NULL, ':'));
	object->next_object = e->object;
	printf("%s\n", line);
	free(line);
	object->v_normal = get_vector_n(fd);
	return (object);
}

int				get_type(char *str)
{
	if (ft_strcmp(str, "sphere") == 0)
		return (1);
	if (ft_strcmp(str, "cylindre") == 0)
		return (2);
	if (ft_strcmp(str, "plane") == 0)
		return (3);
	return (0);
}
