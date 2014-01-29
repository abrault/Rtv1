/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrault <abrault@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/29 11:36:04 by abrault           #+#    #+#             */
/*   Updated: 2014/01/29 19:09:21 by abrault          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_H
# define RT_H

# include <mlx.h>
# include <X11/X.h>
# include <X11/Xlib.h>

# define H_WIN				500
# define W_WIN				800
# define KEY_ESC			65307
# define PI					3.14159265359

typedef struct s_env		t_env;
typedef struct s_img		t_img;
typedef struct s_point		t_point;
typedef struct s_scene		t_scene;
typedef struct s_object		t_object;

struct						s_env
{
	void					*mlx;
	void					*win;
	t_img					*img;
	t_scene					*scene;
	t_object				*object;
	int						expose;
};

struct						s_point
{
	int						x;
	int						y;
	int						red;
	int						green;
	int						blue;
};

struct						s_img
{
	XImage					*image;
	Pixmap					pix;
	GC						gc;
	int						size_line;
	int						bpp;
	int						width;
	int						height;
	int						type;
	int						format;
	char					*data;
	int						endian;
};

struct						s_scene
{
	int						x;
	int						y;
	int						z;
	int						angle;
};

struct						s_object
{
	char					type;
	int						x;
	int						y;
	int						z;
	int						scale;
	t_object				*next_object;
};

void						display_error(int code);
void						mlx_pixel_put_to_image(t_env *e, t_point *point);
t_env						*ini_env(t_env *e);
int							draw_image(t_env *e);
int							expose_hook(t_env *e);
int							loop_hook(t_env *e);
int							key_hook(int keycode, t_env *e);
int							ini_scene_and_object(t_env *e, char *str);
int							get_type(char *str);
t_object					*get_object(t_env *e, int fd);
int							get_scene(t_env *e, int fd);
int							ray_tracing(t_env *e, t_point *point);

#endif
