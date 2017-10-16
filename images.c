/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izelensk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 19:34:17 by izelensk          #+#    #+#             */
/*   Updated: 2017/07/07 19:34:18 by izelensk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		assign_image(int x, int y, t_color color, t_data *d)
{
	d->temp = POS(x, y);
	if (color.b * 255.0 > 255.0)
		color.b = 255.0;
	if (color.r * 255.0 > 255.0)
		color.r = 255.0;
	if (color.g * 255.0 > 255.0)
		color.g = 255.0;
	d->ptr[d->temp] = (int)(color.b * 255.0);
	d->ptr[d->temp + 1] = (int)(color.g * 255.0);
	d->ptr[d->temp + 2] = (int)(color.r * 255.0);
}

t_color		get_image(int x, int y, t_data *d)
{
	t_color		col;

	d->temp = POS(x, y);
	col.b = (double)(d->ptr[d->temp]) / 255.0;
	col.g = (double)(d->ptr[d->temp + 1]) / 255.0;
	col.r = (double)(d->ptr[d->temp + 2]) / 255.0;
	return (col);
}

void		data_init(t_data *d)
{
	d->mlx = mlx_init();
	d->win = mlx_new_window(d->mlx, WIDTH, HEIGHT, "RTv1");
	d->img = mlx_new_image(d->mlx, WIDTH, HEIGHT);
	d->ptr = mlx_get_data_addr(d->img, &(d->bpp),
	&(d->size_line), &(d->endian));
	d->cam.pos = vinit(0.0, 0.0, 0.0);
	d->cam.fov = 66.0;
	d->alpha_x = 0.0;
	d->alpha_y = 0.0;
	d->boost = 0;
	d->gamma = 0.0;
	d->info_flags.plane_count = 0;
	d->info_flags.sphere_count = 0;
	d->info_flags.cylinder_count = 0;
	d->info_flags.cone_count = 0;
	d->info_flags.light_count = 0;
	d->spec = 0;
	d->fuck_up_coef = 0.5;
	d->mirror_coef = 1.0;
}
