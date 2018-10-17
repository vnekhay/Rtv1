/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_and_etc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnekhay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/27 04:22:23 by vnekhay           #+#    #+#             */
/*   Updated: 2018/07/27 04:32:12 by vnekhay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/rtv_1.h"

void			lights_up(S *rtv, int j)
{
	t_colour	a;

	a.colour = rtv->closest_colour;
	rtv->light = rtv->beam_env;
	rtv->reflection = 0;
	rtv->some_vec = vec_mult(&rtv->beam.directional, CLOSDOT) + rtv->camera.ro;
	rtv->R.start.x = rtv->some_vec[0];
	rtv->R.start.y = rtv->some_vec[1];
	rtv->R.start.z = rtv->some_vec[2];
	REFLCOL[0] = 0;
	REFLCOL[1] = 0;
	REFLCOL[2] = 0;
	REFLCOL[3] = 0;
	lights_up_adds(rtv, j, 0);
	a.arr[0] = ((a.arr[0] * rtv->light + REFLCOL[0]) > F) ? F : a.arr[0] * \
	rtv->light + REFLCOL[0];
	a.arr[1] = ((a.arr[1] * rtv->light + REFLCOL[1]) > F) ? F : a.arr[1] * \
	rtv->light + REFLCOL[1];
	a.arr[2] = ((a.arr[2] * rtv->light + REFLCOL[2]) > F) ? F : a.arr[2] * \
	rtv->light + REFLCOL[2];
	rtv->closest_colour = a.colour;
}

void			closest_dots(S *rtv, int j)
{
	if (rtv->x0 < 0 && rtv->x1 < 0)
		CLOSDOT = CLOSDOT;
	else
	{
		if (rtv->x0 < 0)
			rtv->x0 = rtv->x1;
		else if (rtv->x1 < 0)
			;
		else
			rtv->x0 = (rtv->x0 < rtv->x1) ? rtv->x0 : rtv->x1;
		if (CLOSDOT == -1 || CLOSDOT > rtv->x0)
		{
			CLOSDOT = rtv->x0;
			rtv->closest_colour = OBJ[j]->colour.colour;
			lights_up(rtv, j);
		}
	}
}

void			beams_up(S rtv, int x, int y, int i)
{
	get_beams(&rtv, x, y);
	while (++i < rtv.operands)
	{
		if (rtv.objects[i]->what_is == 3)
			sphere(&rtv, i, rtv.beam);
		else if (rtv.objects[i]->what_is == 2)
			plane(&rtv, i, rtv.beam);
		else if (rtv.objects[i]->what_is == 4)
			cylinder(&rtv, i, rtv.beam);
		else if (rtv.objects[i]->what_is == 5)
			cone(&rtv, i, rtv.beam);
		closest_dots(&rtv, i);
	}
	*(int *)(rtv.image_ptr + (x + y * W_WI) * \
	rtv.btsperpx) = (rtv.closest_dot < 0) ? 0 : rtv.closest_colour;
}

void			*need_to_pthread_up(void *ptr)
{
	int		end;
	int		i;
	t_rtv	*rtv;

	rtv = (t_rtv *)ptr;
	i = rtv->i;
	rtv->i = i + 10000;
	end = i + 10000;
	while (i < end)
	{
		if (i >= W_WI * W_HE)
			pthread_exit(0);
		CLOSDOT = -1;
		beams_up(*rtv, i % W_WI, i / W_WI, -1);
		i++;
	}
	pthread_exit(0);
}

void			draw(t_rtv *rtv)
{
	int				i;
	pthread_t		thr[16];

	rtv->i = 0;
	while (rtv->i < W_WI * W_HE)
	{
		i = 0;
		bzero(thr, sizeof(pthread_t) * 16);
		while (i < 16)
		{
			pthread_create(&thr[i], NULL, need_to_pthread_up, rtv);
			i++;
		}
		i = 0;
		while (i < 16)
		{
			pthread_join(thr[i], NULL);
			i++;
		}
	}
	mlx_put_image_to_window(rtv->mlx_ptr, rtv->win_ptr, rtv->image, 0, 0);
}
