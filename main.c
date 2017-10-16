/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izelensk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 13:31:38 by izelensk          #+#    #+#             */
/*   Updated: 2017/06/01 13:31:39 by izelensk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	camera_and_rays(t_data *d)
{
	d->u = (2 * (((double)d->x + 0.5) / (double)WIDTH) - 1.0)
	* TANG(d->cam.fov / 2.0) * ((double)(WIDTH) / (double)(HEIGHT));
	d->v = (1.0 - 2.0 * (((double)d->y + 0.5) / (double)HEIGHT))
	* TANG(d->cam.fov / 2.0);
	d->raydir = vinit(d->u, d->v, 1.0);
	d->raydir = rotatex(d->raydir, d->alpha_y);
	d->raydir = rotatey(d->raydir, d->alpha_x);
	d->ray = init_ray(d->cam.pos, vnorm(d->raydir), 10000.0);
	d->hit = 0;
	d->hit_shadow = 1;
	if (intersect_something(d))
	{
		d->ires.color = d->temp_color;
		d->ires.normal = d->temp_normal;
		d->ires.dist = d->temp_dist;
		d->hit = 1;
	}
	else
		assign_image(d->x, d->y, init_color(0.9, 0.9, 0.9), d);
}

void	light_and_shadows(t_data *d)
{
	int i;

	i = 0;
	while (i < d->info.light_count)
	{
		d->light_ray_dir = vsub(d->light[i].pos, d->hit_point);
		d->light_dist = vlen(d->light_ray_dir);
		d->d = vdot(d->ires.normal, vnorm(d->light_ray_dir));
		d->ray = init_ray(d->hit_point, vnorm(d->light_ray_dir), d->light_dist);
		if (!d->boost && intersect_something(d))
			d->hit_shadow++;
		if (d->hit_shadow > 1)
			d->d /= (double)d->hit_shadow;
		if (!d->boost)
		{
			d->s = pow(d->d, 96.0);
			d->specular = col_avg(d->specular,
			col_mult_d(d->light[i].col, d->s));
		}

		// t_vector h;
		// t_vector v;
		// t_color diff;
		// t_color spec;

		// d->specular = d->ires.color;
		// v = vsub(d->ray.origin, d->hit_point);
		// h = vmul(vadd(d->light_ray_dir, v), 1 / vlen(vadd(d->light_ray_dir, v)));
		// h = vnorm(h);

		// diff = col_mult_d(d->ires.color, fmax(vdot(d->ires.normal, vnorm(d->light_ray_dir)), 0.0));
		// spec = col_mult_d(d->specular, pow(fmax(vdot(d->ires.normal, h), 0.0) , 50));
		// d->final_color = col_add(diff, spec);

		d->final_color = col_mix(d->final_color, col_mult_d(col_mult(
		d->light[i].col, d->ires.color), d->d ));

		i++;
		if (d->boost)
			break ;
	}
}

void	shadows_and_light(t_data *d)
{
	d->hit_point = vadd(d->ray.origin, vmul(d->ray.dir, d->ires.dist));
	d->final_color = init_color(d->gamma, d->gamma, d->gamma);
	d->specular = init_color(d->gamma, d->gamma, d->gamma);
	d->d = 0.0;
	light_and_shadows(d);
	if (d->spec)
		d->final_color = col_add(d->final_color, d->specular);
	d->final_color = col_clamp(d->final_color);
	//grayscale effect;
	// double gray;
	// gray = (d->final_color.r + d->final_color.g + d->final_color.b) / 3.0;
	// d->final_color = init_color(gray, gray, gray);
	//grayscale effect end;
	assign_image(d->x, d->y, d->final_color, d);
}

void	draw(t_data *d)
{
	d->y = 0;
	while (d->y < HEIGHT)
	{
		d->x = 0;
		while (d->x < WIDTH)
		{
			d->neg = 0;
			camera_and_rays(d);
			if (d->hit)
				shadows_and_light(d);
			if (d->boost && d->y != 0)
				assign_image(d->x, d->y - 1, col_avg(get_image(d->x, d->y - 2,
				d), get_image(d->x, d->y, d)), d);
			d->x++;
		}
		d->y += (1 + d->boost);
	}
	mlx_put_image_to_window(d->mlx, d->win, d->img, 0, 0);
}

int		main(int argc, char **argv)
{
	t_data		d;

	if (argc != 2)
	{
		write(1, "Usage: ./RTv1 [scene]\n", 22);
		write(1, "\tkeys:\n", 7);
		write(1, "\tw,a,s,d,q,e \t- move x,y,z\n", 27);
		write(1, "\t1,2 \t- normal, boost mode\n", 27);
		write(1, "\t3,4 \t- lighness\n", 17);
		write(1, "\tarrows \t- rotate camera\n", 25);
		write(1, "\t+,- \t- fov\n", 12);
		return (0);
	}
	data_init(&d);
	d.nsphere = init_sphere(vinit(-5.0, 0.0, 13.0), 4.0, init_color(0.0, 0.0, 0.0));
	d.ncyl = init_cylinder(vinit(-5.0, 0.0, 13.0), vinit(0.0, 1.0, 0.0), 2.0, init_color(0.0, 0.0, 0.0));
	d.ncube = init_cube(vinit(2.0, 2.0, 5.0), vinit(14.0, 34.0, 1.0), 2.0, init_color(1.0, 0.2, 0.7));
	d.torus = init_torus(vinit(0.0, 0.0, 5.0), (vinit(0.2, 0.2, 1.0)), 4.0, 2.0, init_color(0.0, 1.0, 1.0));
	read_info(argv[1], &d);
	draw(&d);
	mlx_expose_hook(d.win, &expose, &d);
	mlx_loop(d.mlx);
	return (0);
}
