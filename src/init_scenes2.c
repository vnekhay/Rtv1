/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_scenes2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnekhay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/27 04:12:21 by vnekhay           #+#    #+#             */
/*   Updated: 2018/07/27 04:37:06 by vnekhay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/rtv_1.h"

double		vec_size(t_v *yoursizeismine)
{
	double		value;
	t_v			tmp;

	tmp = *yoursizeismine;
	value = sqrt(tmp[0] * tmp[0] + tmp[1] * tmp[1] + tmp[2] * tmp[2]);
	return (value);
}

void		error(char *s)
{
	ft_putendl_fd(s, 2);
	exit(0);
}

int			exit_func(void)
{
	exit(1);
}

void		init_scene_5(t_rtv *rtv)
{
	rtv->operands = 8;
	rtv->num_of_lights = 2;
	scene_init(rtv);
	op_sphere(OBJ[0], COL(65, 105, 225, 0), (t_v){45, 10, 190}, 20);
	op_sphere(OBJ[1], COL(34, 139, 34, 0), (t_v){0, -20, 150}, 25);
	op_sphere(OBJ[7], COL(178, 34, 34, 0), (t_v){-45, 10, 190}, 20);
	op_plane(OBJ[2], COL(255, 105, 80, 0), (t_v){0, -80, 0}, (t_v){0, 1, 0});
	op_plane(OBJ[3], COL(255, 20, 147, 0), (t_v){0, 270, 0}, (t_v){0, -1, 0});
	op_plane(OBJ[4], COL(255, 0, 255, 0), (t_v){160, 0, 150}, (t_v){-1, 0, 0});
	op_plane(OBJ[5], COL(148, 0, 211, 0), (t_v){-160, 0, 150}, (t_v){1, 0, 0});
	LIGHT[0]->colour = COL(F, F, F, 0);
	LIGHT[0]->position = (t_v){120, 210, 260};
	LIGHT[0]->intense = 0.5;
	LIGHT[1]->colour = COL(F, F, F, 0);
	LIGHT[1]->position = (t_v){-90, 212, -70};
	LIGHT[1]->intense = 0.6;
}

void		init_scene_6(t_rtv *rtv)
{
	rtv->operands = 8;
	rtv->num_of_lights = 3;
	scene_init(rtv);
	op_sphere(OBJ[0], COL(75, 0, 130, 1), (t_v){17, 0, 101}, 5);
	op_plane(OBJ[1], COL(200, 200, 250, 0), (t_v){0, -80, 0}, (t_v){0, 1, 0});
	op_plane(OBJ[2], COL(123, 104, 238, 0), (t_v){0, 270, 0}, (t_v){0, -1, 0});
	op_plane(OBJ[3], COL(99, 149, 237, 0), (t_v){160, 0, 150}, (t_v){-1, 0, 0});
	op_plane(OBJ[4], COL(50, 10, 241, 0), (t_v){-160, 0, 150}, (t_v){1, 0, 0});
	op_sphere(OBJ[5], COL(F, 0, 0, 1), (t_v){-10, 0, 191}, 5);
	op_sphere(OBJ[6], COL(0, F, 0, 1), (t_v){-19, 0, 1}, 5);
	op_sphere(OBJ[7], COL(0, 0, F, 1), (t_v){9, 0, 600}, 5);
	LIGHT[0]->colour = COL(F, F, F, 0);
	LIGHT[0]->position = (t_v){60, 10, -60};
	LIGHT[0]->intense = 0.2;
	LIGHT[1]->colour = COL(F, F, F, 0);
	LIGHT[1]->position = (t_v){-60, 25, 60};
	LIGHT[1]->intense = 0.2;
	LIGHT[2]->colour = COL(F, F, F, 0);
	LIGHT[2]->position = (t_v){10, 10, 0};
	LIGHT[2]->intense = 0.4;
}
