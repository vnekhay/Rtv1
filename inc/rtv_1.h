/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv_1.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnekhay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/27 03:39:25 by vnekhay           #+#    #+#             */
/*   Updated: 2018/07/27 03:39:27 by vnekhay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV_1_H
# define RTV_1_H

# include <pthread.h>
# include "mlx.h"
# include <math.h>
# include "libft.h"

# define W_WI 1000
# define W_HE 1000
# define USAGE "Usage : ./RTv1 scene_number `1-6`"
# define S t_rtv
# define LIGHT rtv->lights
# define REFLCOL rtv->reflection_colour.arr
# define REFL rtv->reflection
# define OBJ rtv->objects
# define COL init_colour
# define DISP camera.display
# define F 255
# define CLOSDOT rtv->closest_dot
# define DOT dot_product
# define DATADR mlx_get_data_addr
# define R beams

typedef double		t_v __attribute__((vector_size(sizeof(double)*3)));

typedef struct		s_svector
{
	double			z;
	double			y;
	double			x;
}					t_svector;

typedef	union		u_colour
{
	unsigned char	arr[4];
	unsigned long	colour;
}					t_colour;

typedef struct		s_vector_o
{
	double			width;
	double			height;
	double			distance;
	t_v				ro;
	t_v				id;
	t_svector		display;
}					t_vector_o;

typedef struct		s_operands
{
	int				what_is;
	double			radian;
	double			alpha;
	t_v				position;
	t_v				offset;
	t_colour		colour;
}					t_operands;

typedef struct		s_light
{
	double			intense;
	t_v				position;
	t_colour		colour;
}					t_light;

typedef struct		s_beams
{
	t_v				directional;
	t_svector		start;
}					t_beams;

typedef struct		s_rtv
{
	char			*image_ptr;
	int				i;
	int				sl;
	int				end;
	int				operands;
	int				btsperpx;
	int				num_of_lights;
	int				closest_colour;
	double			x0;
	double			x1;
	double			closest_dot;
	double			beam_env;
	double			light;
	double			reflection;
	t_colour		reflection_colour;
	t_beams			beam;
	t_beams			beams;
	t_light			**lights;
	t_operands		**objects;
	t_v				some_vec;
	t_vector_o		default_camera;
	t_vector_o		camera;
	void			*image;
	void			*win_ptr;
	void			*mlx_ptr;
}					t_rtv;

void				error(char *s);
double				vec_size(t_v *yoursizeismine);
t_v					vec_normalize(t_v *needtonorm);
void				get_beams(S *rtv, int x, int y);
void				reflection(S *rtv, int j, double dot);
double				the_shade(S *rtv, int j, t_beams ray);
double				dot_product(t_v *dot_operand, t_v *dot_operand2);
void				lights_up_adds(S *rtv, int i, int j);
t_v					vec_mult(t_v *needtomult, double mult);
void				lights_up(S *rtv, int j);
void				closest_dots(S *rtv, int j);
void				beams_up(S rtv, int x, int y, int i);
void				*need_to_pthread_up(void *ptr);
void				draw(t_rtv *rtv);
t_v					minus_vector(t_v *i, t_v *j);
void				quadra_equa(t_rtv *rtv, double a, double b, double c);
void				sphere(t_rtv *rtv, int i, t_beams ray);
void				plane(t_rtv *rtv, int i, t_beams ray);
void				cylinder(t_rtv *rtv, int i, t_beams ray);
void				cone(t_rtv *rtv, int i, t_beams ray);
t_rtv				*o_rotation(t_rtv *rtv, int key_num);
t_rtv				*default_position(t_rtv *rtv);
int					key_hook(int key_num, t_rtv *rtv);
t_v					find_norm(t_rtv *rtv, int i, t_v pos);
t_colour			init_colour(int red, int blue, int green, int alpha);
void				op_sphere(t_operands *op, t_colour c, t_v pos, double ra);
void				op_cyl(t_operands *op, t_colour c, t_v pos, t_v offset);
void				op_plane(t_operands *op, t_colour c, t_v pos, t_v offset);
void				op_cone(t_operands *op, t_colour c, t_v pos, t_v offset);
void				scene_init(t_rtv *rtv);
void				init_scene_6(t_rtv *rtv);
void				init_scene_5(t_rtv *rtv);
void				init_scene_4_adds(t_rtv *rtv);
void				init_scene_4(t_rtv *rtv);
void				init_scene_3(t_rtv *rtv);
void				init_scene_2(t_rtv *rtv);
void				init_scene_1(t_rtv *rtv);
void				init(t_rtv *rtv);
int					exit_func(void);
void				choose_scene(char scene, t_rtv *rtv);

#endif
