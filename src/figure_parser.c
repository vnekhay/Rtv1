/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figure_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnekhay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/27 04:18:54 by vnekhay           #+#    #+#             */
/*   Updated: 2018/07/27 04:31:32 by vnekhay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/rtv_1.h"

void				op_sphere(t_operands *op, t_colour c, t_v pos, double ra)
{
	op->what_is = 3;
	op->colour = c;
	op->position = pos;
	op->radian = ra;
}

void				op_cyl(t_operands *op, t_colour c, t_v pos, t_v offset)
{
	op->what_is = 4;
	op->colour = c;
	op->position = pos;
	op->offset = offset;
	op->radian = 4;
}

void				op_plane(t_operands *op, t_colour c, t_v pos, t_v offset)
{
	op->what_is = 2;
	op->colour = c;
	op->position = pos;
	op->offset = offset;
}

void				op_cone(t_operands *op, t_colour c, t_v pos, t_v offset)
{
	op->what_is = 5;
	op->colour = c;
	op->position = pos;
	op->offset = offset;
	op->radian = 10;
	op->alpha = 40;
}

t_rtv				*o_rotation(t_rtv *rtv, int key_num)
{
	if (key_num == 123)
		rtv->camera.ro[0] += 0.1;
	else if (key_num == 124)
		rtv->camera.ro[0] -= 0.1;
	else if (key_num == 126)
		rtv->camera.ro[2] += 10;
	else if (key_num == 125)
		rtv->camera.ro[2] -= 10;
	return (rtv);
}
