/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv_additions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnekhay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/27 04:15:45 by vnekhay           #+#    #+#             */
/*   Updated: 2018/07/27 04:33:51 by vnekhay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/rtv_1.h"

t_v				vec_normalize(t_v *needtonorm)
{
	double		norm;
	t_v			normalized;

	normalized = *needtonorm;
	norm = vec_size(needtonorm);
	if (norm != 0)
	{
		normalized[0] = normalized[0] / norm;
		normalized[1] = normalized[1] / norm;
		normalized[2] = normalized[2] / norm;
	}
	return (normalized);
}

double			dot_product(t_v *dot_operand, t_v *dot_operand2)
{
	double		result;
	t_v			tmp;
	t_v			tmp2;

	tmp = *dot_operand;
	tmp2 = *dot_operand2;
	result = tmp[0] * tmp2[0] + tmp[1] * tmp2[1] + tmp[2] * tmp2[2];
	return (result);
}

t_v				vec_mult(t_v *needtomult, double mult)
{
	t_v			before_mult;
	t_v			after_mult;

	before_mult = *needtomult;
	after_mult[0] = before_mult[0] * mult;
	after_mult[1] = before_mult[1] * mult;
	after_mult[2] = before_mult[2] * mult;
	return (after_mult);
}

t_v				minus_vector(t_v *i, t_v *j)
{
	t_v		a;
	t_v		b;
	t_v		c;

	a = *i;
	b = *j;
	c[0] = a[0] - b[0];
	c[1] = a[1] - b[1];
	c[2] = a[2] - b[2];
	return (c);
}

t_rtv			*default_position(t_rtv *rtv)
{
	rtv->camera.ro[0] = rtv->default_camera.ro[0];
	rtv->camera.ro[1] = rtv->default_camera.ro[1];
	rtv->camera.ro[2] = rtv->default_camera.ro[2];
	rtv->camera.id = rtv->default_camera.id;
	return (rtv);
}
