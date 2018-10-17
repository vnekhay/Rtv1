/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shade_reflection.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnekhay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/27 04:24:00 by vnekhay           #+#    #+#             */
/*   Updated: 2018/07/27 04:36:34 by vnekhay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/rtv_1.h"

void			get_beams(S *rtv, int x, int y)
{
	rtv->DISP.x = x - W_WI / 2;
	rtv->DISP.y = (W_HE - y) - W_HE / 2;
	rtv->beam.start.x = (double)rtv->camera.ro[0];
	rtv->beam.start.y = (double)rtv->camera.ro[1];
	rtv->beam.start.z = (double)rtv->camera.ro[2];
	rtv->beam.directional[0] = rtv->DISP.x * \
	(rtv->default_camera.width / W_WI) - rtv->camera.ro[0];
	rtv->beam.directional[1] = rtv->DISP.y * \
	(rtv->default_camera.height / W_HE) - rtv->camera.ro[1];
	rtv->beam.directional[2] = rtv->DISP.z;
}

void			reflection(S *rtv, int j, double dot)
{
	REFL = exp(-250 * (1.0 - dot) / dot);
	REFLCOL[0] = (REFLCOL[0] + LIGHT[j]->colour.arr[0] * REFL * \
	LIGHT[j]->intense > F) ? F : (REFLCOL[0] + \
	LIGHT[j]->colour.arr[0] * REFL * LIGHT[j]->intense);
	REFLCOL[1] = (REFLCOL[1] + LIGHT[j]->colour.arr[1] * REFL * \
	LIGHT[j]->intense > F) ? F : (REFLCOL[1] + \
	LIGHT[j]->colour.arr[1] * REFL * LIGHT[j]->intense);
	REFLCOL[2] = (REFLCOL[2] + LIGHT[j]->colour.arr[2] * REFL * \
	LIGHT[j]->intense > F) ? F : (REFLCOL[2] + \
	LIGHT[j]->colour.arr[2] * REFL * LIGHT[j]->intense);
}

double			the_shade(S *rtv, int j, t_beams ray)
{
	int				i;
	double			value;
	double			result;

	i = -1;
	result = 0.0;
	ray.directional = vec_normalize(&ray.directional);
	value = vec_size(&ray.directional);
	while (++i < rtv->operands)
	{
		rtv->x0 = 0;
		if (i == j)
			continue;
		else if (OBJ[i]->what_is == 2)
			plane(rtv, i, ray);
		else if (OBJ[i]->what_is == 3)
			sphere(rtv, i, ray);
		else if (OBJ[i]->what_is == 4)
			cylinder(rtv, i, ray);
		else if (OBJ[i]->what_is == 5)
			cone(rtv, i, ray);
		if (rtv->x0 > 0.1 && rtv->x0 < value)
			result += rtv->x0;
	}
	return (result);
}

t_v				find_norm(t_rtv *rtv, int i, t_v pos)
{
	double	m;
	t_v		n;
	t_v		oc;

	if (OBJ[i]->what_is == 4 || OBJ[i]->what_is == 5)
	{
		oc[0] = (rtv->beam.start.x - OBJ[i]->position[0]);
		oc[1] = (rtv->beam.start.y - OBJ[i]->position[1]);
		oc[2] = (rtv->beam.start.z - OBJ[i]->position[2]);
		m = DOT(&rtv->beam.directional, &OBJ[i]->offset) * rtv->x0 + \
		DOT(&oc, &OBJ[i]->offset);
		n = pos - OBJ[i]->position - vec_mult(&OBJ[i]->offset, m);
		if (OBJ[i]->what_is == 5)
			n = n - vec_mult(&OBJ[i]->offset, m * \
			tan((OBJ[i]->alpha / 2) * 3.141 / 180) * \
			tan((OBJ[i]->alpha / 2) * 3.141 / 180));
	}
	else if (OBJ[i]->what_is == 2)
		n = OBJ[i]->offset;
	if (OBJ[i]->what_is == 3)
		n = minus_vector(&pos, &OBJ[i]->position);
	n = vec_normalize(&n);
	return (n);
}

void			lights_up_adds(S *rtv, int i, int j)
{
	t_v		vec_pc;
	double	dot_pr;
	t_v		vec_h;
	t_v		vec_v;
	t_v		vec_l;

	vec_pc = find_norm(rtv, i, rtv->some_vec);
	vec_v = rtv->camera.ro - rtv->some_vec;
	vec_v = vec_normalize(&vec_v);
	while (j < rtv->num_of_lights)
	{
		rtv->R.directional = LIGHT[j]->position - rtv->some_vec;
		if ((the_shade(rtv, i, rtv->R)) == 0)
		{
			vec_l = vec_normalize(&rtv->R.directional);
			vec_h = vec_l + vec_v;
			vec_h = vec_normalize(&vec_h);
			dot_pr = DOT(&vec_pc, &vec_l);
			dot_pr = dot_pr < 0 ? 0 : dot_pr;
			rtv->light += dot_pr * LIGHT[j]->intense;
			reflection(rtv, j, DOT(&vec_h, &vec_pc) * DOT(&vec_h, &vec_pc));
		}
		j++;
	}
}
