/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_equations.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnekhay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/27 04:21:22 by vnekhay           #+#    #+#             */
/*   Updated: 2018/07/27 04:34:30 by vnekhay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/rtv_1.h"

void		quadra_equa(t_rtv *rtv, double a, double b, double c)
{
	double	d;

	d = b * b - 4 * a * c;
	if (d >= 0 && a != 0)
	{
		if (d == 0)
		{
			rtv->x0 = -0.5 * b / a;
			rtv->x1 = rtv->x0;
		}
		else
		{
			rtv->x0 = (-b + sqrt(d)) / (2 * a);
			rtv->x1 = (-b - sqrt(d)) / (2 * a);
		}
	}
	else
	{
		rtv->x0 = -1;
		rtv->x1 = -1;
	}
}

void		sphere(t_rtv *rtv, int i, t_beams ray)
{
	double	a;
	double	b;
	double	c;
	t_v		oc;
	double	deskr;

	a = DOT(&ray.directional, &ray.directional);
	oc[0] = (ray.start.x - OBJ[i]->position[0]);
	oc[1] = (ray.start.y - OBJ[i]->position[1]);
	oc[2] = (ray.start.z - OBJ[i]->position[2]);
	b = 2 * DOT(&oc, &ray.directional);
	c = DOT(&oc, &oc) - (OBJ[i]->radian * OBJ[i]->radian);
	quadra_equa(rtv, a, b, c);
}

void		plane(t_rtv *rtv, int i, t_beams ray)
{
	double	a;
	double	b;
	t_v		oc;

	oc[0] = (ray.start.x - OBJ[i]->position[0]);
	oc[1] = (ray.start.y - OBJ[i]->position[1]);
	oc[2] = (ray.start.z - OBJ[i]->position[2]);
	OBJ[i]->offset = vec_normalize(&OBJ[i]->offset);
	a = -(DOT(&oc, &OBJ[i]->offset));
	b = DOT(&ray.directional, &OBJ[i]->offset);
	if (b != 0)
		rtv->x0 = a / b;
	else
		rtv->x0 = -1;
	if (rtv->x0 < 0.0001)
		rtv->x0 = -1;
	rtv->x1 = rtv->x0;
}

void		cylinder(t_rtv *rtv, int i, t_beams ray)
{
	double	a;
	double	b;
	double	c;
	t_v		oc;

	OBJ[i]->offset = vec_normalize(&OBJ[i]->offset);
	a = (DOT(&ray.directional, &ray.directional) - (DOT(&ray.directional, \
	&OBJ[i]->offset) * DOT(&ray.directional, &OBJ[i]->offset)));
	oc[0] = (ray.start.x - OBJ[i]->position[0]);
	oc[1] = (ray.start.y - OBJ[i]->position[1]);
	oc[2] = (ray.start.z - OBJ[i]->position[2]);
	b = 2 * (DOT(&ray.directional, &oc) - DOT(&ray.directional, \
	&OBJ[i]->offset) * DOT(&oc, &OBJ[i]->offset));
	c = (DOT(&oc, &oc) - DOT(&oc, &OBJ[i]->offset) * DOT(&oc, \
	&OBJ[i]->offset) - (OBJ[i]->radian * OBJ[i]->radian));
	quadra_equa(rtv, a, b, c);
}

void		cone(t_rtv *rtv, int i, t_beams ray)
{
	double	a;
	double	b;
	double	c;
	t_v		oc;
	double	k;

	k = tan((OBJ[i]->alpha / 2) * 3.141 / 180);
	OBJ[i]->offset = vec_normalize(&OBJ[i]->offset);
	oc[0] = (ray.start.x - OBJ[i]->position[0]);
	oc[1] = (ray.start.y - OBJ[i]->position[1]);
	oc[2] = (ray.start.z - OBJ[i]->position[2]);
	a = DOT(&ray.directional, &ray.directional) - (1 + k * k) * DOT(&ray.\
	directional, &OBJ[i]->offset) * DOT(&ray.directional, &OBJ[i]->offset);
	b = 2 * (DOT(&ray.directional, &oc) - (1 + k * k) * DOT(&ray.directional, \
	&OBJ[i]->offset) * DOT(&oc, &OBJ[i]->offset));
	c = DOT(&oc, &oc) - (1 + k * k) * DOT(&oc, &OBJ[i]->offset) * \
	DOT(&oc, &OBJ[i]->offset);
	quadra_equa(rtv, a, b, c);
}
