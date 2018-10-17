/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_scenes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnekhay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/27 04:10:48 by vnekhay           #+#    #+#             */
/*   Updated: 2018/07/27 04:33:29 by vnekhay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/rtv_1.h"

void			init_scene_1(t_rtv *rtv)
{
	rtv->operands = 1;
	rtv->num_of_lights = 3;
	scene_init(rtv);
	op_sphere(OBJ[0], COL(85, 5, 5, 0), (t_v){0, 0, 40}, 25);
	LIGHT[0]->colour = COL(F, F, F, 0);
	LIGHT[0]->position = (t_v){200, 200, 30};
	LIGHT[0]->intense = 0.6;
	LIGHT[1]->colour = COL(F, F, F, 0);
	LIGHT[1]->position = (t_v){80, 200, 0};
	LIGHT[1]->intense = 0.6;
	LIGHT[2]->colour = COL(F, F, F, 0);
	LIGHT[2]->position = (t_v){0, 40, -50};
	LIGHT[2]->intense = 0.6;
}

void			init_scene_2(t_rtv *rtv)
{
	rtv->operands = 2;
	rtv->num_of_lights = 2;
	scene_init(rtv);
	op_cone(OBJ[0], COL(200, 179, 50, 0), (t_v){0, 0, 0}, (t_v){0, 1, 0});
	op_plane(OBJ[1], COL(7, 4, 200, 0), (t_v){10, -30, 0}, (t_v){0, 1, 0});
	LIGHT[0]->colour = COL(F, F, F, 0);
	LIGHT[0]->position = (t_v){0, 200, -130};
	LIGHT[0]->intense = 0.6;
	LIGHT[1]->colour = COL(F, F, F, 0);
	LIGHT[1]->position = (t_v){-80, 200, 0};
	LIGHT[1]->intense = 0.6;
}

void			init_scene_3(t_rtv *rtv)
{
	rtv->operands = 1;
	rtv->num_of_lights = 1;
	scene_init(rtv);
	op_cyl(OBJ[0], COL(0, 235, 0, 0), (t_v){0, 0, 0}, (t_v){0, 0, 1});
	LIGHT[0]->colour = COL(F, F, F, 0);
	LIGHT[0]->position = (t_v){200, 100, -60};
	LIGHT[0]->intense = 0.3;
}

void			init_scene_4_adds(t_rtv *rtv)
{
	op_sphere(OBJ[7], COL(39, 0, 39, 0), (t_v){20, 25, 70}, 10);
	op_sphere(OBJ[8], COL(39, 0, 39, 0), (t_v){-20, 25, 70}, 10);
	op_cyl(OBJ[11], COL(20, 0, 40, 0), (t_v){20, 0, 70}, (t_v){0, 1, 0});
	op_cyl(OBJ[12], COL(20, 0, 40, 0), (t_v){-20, 0, 70}, (t_v){0, 1, 0});
	LIGHT[0]->colour = COL(F, F, F, 0);
	LIGHT[0]->position = (t_v){40, 18, -50};
	LIGHT[0]->intense = 0.6;
	LIGHT[1]->colour = COL(F, F, F, 0);
	LIGHT[1]->position = (t_v){-40, 18, -50};
	LIGHT[1]->intense = 0.6;
}

void			init_scene_4(t_rtv *rtv)
{
	rtv->operands = 16;
	rtv->num_of_lights = 2;
	scene_init(rtv);
	op_sphere(OBJ[0], COL(75, 0, 130, 0), (t_v){20, -20, 70}, 10);
	op_sphere(OBJ[1], COL(75, 0, 130, 0), (t_v){-20, -20, 70}, 10);
	op_plane(OBJ[4], COL(255, 20, 147, 0), (t_v){0, -20, 0}, (t_v){0, 1, 0});
	op_plane(OBJ[5], COL(255, 20, 147, 0), (t_v){0, 25, 0}, (t_v){0, -1, 0});
	op_plane(OBJ[6], COL(255, 20, 147, 0), (t_v){0, 0, 300}, (t_v){0, 0, 1});
	op_sphere(OBJ[15], COL(75, 0, 130, 0), (t_v){0, -13, 90}, 5);
	init_scene_4_adds(rtv);
}
