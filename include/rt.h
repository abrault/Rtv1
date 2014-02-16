/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrault <abrault@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/29 11:36:04 by abrault           #+#    #+#             */
/*   Updated: 2014/02/16 19:42:41 by abrault          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_H
# define RT_H

# include <mlx.h>
# include <X11/X.h>
# include <X11/Xlib.h>

# define H_WIN				960.0
# define W_WIN				1280.0
# define KEY_ESC			65307
# define V_WIDTH			0.5
# define V_DIST				1.0
# define V_HEIGHT			(V_DIST / 2.0) / (W_WIN / H_WIN)

typedef struct s_env		t_env;
typedef struct s_img		t_img;
typedef struct s_point		t_point;
typedef struct s_scene		t_scene;
typedef struct s_object		t_object;
typedef struct s_ray		t_ray;
typedef struct s_vector		t_vector;

struct						s_env
{
	void					*mlx;
	void					*win;
	t_img					*img;
	t_scene					*scene;
	t_object				*object;
	int						expose;
	float					t;
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
};

struct						s_vector
{
	float					x;
	float					y;
	float					z;
};

struct						s_object
{
	char					type;
	int						x;
	int						y;
	int						z;
	int						scale;
	int						r;
	int						g;
	int						b;
	t_object				*next_object;
	t_vector				*v_normal;
};

void		display_error(int code);
void		mlx_pixel_put_to_image(t_env *e, t_point *point);
t_env		*ini_env(t_env *e);
int			draw_image(t_env *e);
int			expose_hook(t_env *e);
int			loop_hook(t_env *e);
int			key_hook(int keycode, t_env *e);
int			ini_scene_and_object(t_env *e, char *str);
int			get_type(char *str);
t_object	*get_object(t_env *e, int fd);
t_scene		*get_scene(int fd);
t_vector	*ray_tracing(t_env *e, t_point *point);
float		ft_pow(float nb, float n);
float		carre(float i);
float		find_inter_sphere(t_scene *o, t_vector *dir, t_object *ob);
float		find_inter_plane(t_scene *o, t_vector *dir, t_object *ob);

#endif
