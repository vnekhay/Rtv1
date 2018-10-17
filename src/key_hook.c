/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnekhay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/27 04:35:21 by vnekhay           #+#    #+#             */
/*   Updated: 2018/07/27 04:35:43 by vnekhay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/rtv_1.h"

int				key_hook(int key_num, t_rtv *rtv)
{
	if (key_num == 53)
	{
		mlx_destroy_image(rtv->mlx_ptr, rtv->image);
		mlx_destroy_window(rtv->mlx_ptr, rtv->win_ptr);
		exit(0);
	}
	else if (key_num == 49)
		rtv = default_position(rtv);
	else if (key_num >= 123 && key_num <= 126)
		rtv = o_rotation(rtv, key_num);
	mlx_clear_window(rtv->mlx_ptr, rtv->win_ptr);
	draw(rtv);
	return (0);
}
