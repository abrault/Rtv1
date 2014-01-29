/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrault <abrault@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/29 13:45:38 by abrault           #+#    #+#             */
/*   Updated: 2014/01/29 15:23:41 by abrault          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <rt.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

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
				get_scene(e, fd);
			else if (ft_strstr(line, "object"))
				e->object = get_object(e, fd);
		}
	}
	return (1);
}

int				get_scene(t_env *e, int fd)
{
	char		*line;

	get_next_line(fd, &line);
	free(line);
	e->scene->x = ft_atoi(ft_strtok(line, ':'));
	e->scene->y = ft_atoi(ft_strtok(NULL, ':'));
	e->scene->z = ft_atoi(ft_strtok(NULL, ':'));
	get_next_line(fd, &line);
	e->scene->angle = ft_atoi(line);
	free(line);
	return (1);
}

t_object		*get_object(t_env *e, int fd)
{
	t_object	*object;
	char		*line;

	object = malloc(sizeof(t_object));
	get_next_line(fd, &line);
	object->type = get_type(line);
	get_next_line(fd, &line);
	free(line);
	object->x = ft_atoi(ft_strtok(line, ':'));
	object->y = ft_atoi(ft_strtok(NULL, ':'));
	object->z = ft_atoi(ft_strtok(NULL, ':'));
	get_next_line(fd, &line);
	object->scale = ft_atoi(line);
	object->next_object = e->object;
	free(line);
	return (object);
}

int				get_type(char *str)
{
	if (ft_strcmp(str, "sphere") == 0)
		return (1);
	if (ft_strcmp(str, "cylindre") == 0)
		return (2);
	return (0);
}
