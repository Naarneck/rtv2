/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izelensk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 19:23:31 by izelensk          #+#    #+#             */
/*   Updated: 2017/07/07 19:23:33 by izelensk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		rtv_exit(t_data *d)
{
	mlx_destroy_image(d->mlx, d->img);
	mlx_destroy_window(d->mlx, d->win);
	write(1, "Thx for attention\n", 18);
	exit(0);
}

int		key_press(int key, t_data *d)
{
	if (key == KEY_ESC)
		rtv_exit(d);
	if (key == KEY_TWO)
		d->boost = 1;
	if (key == KEY_ONE)
		d->boost = 0;
	if (key == KEY_FIVE)
		d->spec = 0;
	if (key == KEY_SIX)
		d->spec = 1;
	if (key == KEY_FOUR && d->gamma <= 10.0)
		d->gamma += 0.2;
	if (key == KEY_THREE && d->gamma >= -10.0)
		d->gamma -= 0.2;
	if (key == KEY_PLUS && d->cam.fov < 120.0)
		d->cam.fov *= 1.1;
	if (key == KEY_MINUS && d->cam.fov > 30.0)
		d->cam.fov *= 0.9;
	if (key == KEY_Q)
		d->cam.pos.y += 0.2;
	if (key == KEY_E)
		d->cam.pos.y -= 0.2;
	if (key == KEY_LEFT)
		d->cam.pos.x -= 0.2;
	if (key == KEY_RIGHT)
		d->cam.pos.x += 0.2;
	if (key == KEY_UP)
		d->cam.pos.z += 0.2;
	if (key == KEY_DOWN)
		d->cam.pos.z -= 0.2;
	if (key == KEY_ALEFT)
		d->alpha_x += 3.0;
	if (key == KEY_ARIGHT)
		d->alpha_x -= 3.0;
	if (key == KEY_AUP)
		d->alpha_y += 3.0;
	if (key == KEY_ADOWN)
		d->alpha_y -= 3.0;
	if (key == KEY_SHIFT)
		d->fuck_up_coef *= 1.3;
	if (key == KEY_CTRL)
		d->fuck_up_coef *= 0.7;
	if (key == KEY_RSHIFT)
		d->mirror_coef -= 0.2;
	if (key == KEY_RCTRL)
		d->mirror_coef += 0.2;
	draw(d);
	return (0);
}

// int		key_release(int key, t_data *d)
// {
// 	d->fuck_up_coef = d->fuck_up_coef;
// 	key = key  * 1;
// 	//draw(d);
// 	return (0);
// }

int		expose(t_data *d)
{
	mlx_key_hook(d->win, &key_press, d);
	//mlx_hook(d->win, 2, 1L, &key_release, d);
	mlx_hook(d->win, 17, 1L << 17, &rtv_exit, d);
	return (0);
}
