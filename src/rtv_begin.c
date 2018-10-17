/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv_begin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnekhay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/27 04:08:19 by vnekhay           #+#    #+#             */
/*   Updated: 2018/07/27 04:34:50 by vnekhay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/rtv_1.h"

t_colour		init_colour(int red, int blue, int green, int alpha)
{
	t_colour	colour;

	colour.arr[2] = red;
	colour.arr[1] = blue;
	colour.arr[0] = green;
	colour.arr[3] = alpha;
	return (colour);
}

void			scene_init(t_rtv *rtv)
{
	int			j;

	j = -1;
	OBJ = (t_operands**)malloc(sizeof(t_operands*) * rtv->operands);
	LIGHT = (t_light**)malloc(sizeof(t_light*) * rtv->num_of_lights);
	while (++j < rtv->operands)
		OBJ[j] = (t_operands*)malloc(sizeof(t_operands));
	j = -1;
	while (++j < rtv->num_of_lights)
		LIGHT[j] = (t_light*)malloc(sizeof(t_light));
}

void			init(t_rtv *rtv)
{
	rtv->default_camera.ro = (t_v){0, 0, -100};
	rtv->camera.ro = rtv->default_camera.ro;
	rtv->camera.distance = 1;
	rtv->default_camera.width = 0.5;
	rtv->default_camera.height = 0.5;
	rtv->DISP.z = rtv->camera.distance;
	rtv->beam_env = 0.3;
}

void			choose_scene(char scene, t_rtv *rtv)
{
	if (scene == 49)
		init_scene_1(rtv);
	if (scene == 50)
		init_scene_2(rtv);
	if (scene == 51)
		init_scene_3(rtv);
	if (scene == 52)
		init_scene_4(rtv);
	if (scene == 53)
		init_scene_5(rtv);
	if (scene == 54)
		init_scene_6(rtv);
}

int				main(int argc, char *argv[])
{
	t_rtv	rtv;

	if (argc == 2 && strlen(argv[1]) == 1 && \
		argv[1][0] != '0' && argv[1][0] != '9' && \
		argv[1][0] != '8' && argv[1][0] != '7')
	{
		rtv.mlx_ptr = mlx_init();
		rtv.win_ptr = mlx_new_window(rtv.mlx_ptr, W_WI, W_HE, "vnekhay RTv1");
		rtv.image = mlx_new_image(rtv.mlx_ptr, W_WI, W_HE);
		rtv.image_ptr = DATADR(rtv.image, &rtv.btsperpx, &rtv.sl, &rtv.end);
		rtv.btsperpx = rtv.btsperpx / 8;
		choose_scene(*argv[1], &rtv);
		init(&rtv);
		draw(&rtv);
		mlx_hook(rtv.win_ptr, 2, 0, key_hook, &rtv);
		mlx_hook(rtv.win_ptr, 17, 1L << 17, exit_func, 0);
		mlx_loop(rtv.mlx_ptr);
	}
	else
		error(USAGE);
	return (0);
}
