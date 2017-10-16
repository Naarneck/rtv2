/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytrace.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izelensk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 20:27:32 by izelensk          #+#    #+#             */
/*   Updated: 2017/07/22 15:46:01 by izelensk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#define HP vadd(d->ray.origin, vmul(d->ray.dir, d->ray_dist))
#define ITR init_temp_res
#define	DIA(a) sqrt(2.0) * a

void	init_temp_res(t_color col, t_vector vec, t_data *d)
{
	d->temp_dist = d->ray_dist;
	d->temp_color = col;
	d->temp_normal = vec;
}

void	plane_sphere_part(t_data *d)
{
	int i;

	i = -1;
	d->temp_dist = d->ray.dist + 0.1;
	while (++i < d->info.plane_count)
		if (plane_intersect(d, d->plane[i]) && d->ray_dist < d->temp_dist)
		{
			if (vdot(d->ray.dir, d->plane[i].normal) < 0.0)
				ITR(d->plane[i].col, vnorm(d->plane[i].normal), d);
			else
				ITR(d->plane[i].col, vnorm(vmul(d->plane[i].normal, -1.0)), d);
		}
	i = -1;
	while (++i < d->info.sphere_count)
		if (sphere_intersect(d, d->sphere[i]) && d->ray_dist < d->temp_dist)
		{
			d->something = vinit((rand() % 100) * 0.01 * d->fuck_up_coef, (rand() % 100) * 0.01 * d->fuck_up_coef, (rand() % 100) * 0.01 * d->fuck_up_coef);
			d->ray_dist_backup = d->ray_dist;
			d->color_backup = d->sphere[i].col;
			d->ray = init_ray(HP, vnorm(vadd(vsub(HP, d->sphere[i].pos), d->something)), 1000.0);
			//ITR(d->sphere[i].col, vnorm(vsub(HP, d->sphere[i].pos)), d);
			intersect_something(d);
			//d->temp_color = col_mix(col_mult_d(d->temp_color, 1.0), col_mult_d(d->sphere[i].col, 1.0));
			d->temp_color = col_add(col_mult_d(d->temp_color, d->mirror_coef), col_mult_d(d->sphere[i].col, (1.0 - d->mirror_coef)));
			// d->temp_normal = vnorm(vsub(HP, d->sphere[i].pos));
			d->ray_dist = d->ray_dist_backup;
		}
}

int		intersect_something(t_data *d)
{
	int i;
	int temp;

	temp = 0;
	plane_sphere_part(d);
	i = -1;
	while (++i < d->info.cone_count)
	{
		if (cone_intersect(d, d->cone[i]) && d->ray_dist < d->temp_dist && !d->neg)
		{
			ITR(d->cone[i].col, vnorm(vsub(vsub(HP, d->cone[i].pos),
			vmul(d->cone[i].dir, (1.0 + d->cone[i].angle * d->cone[i].angle)
			* d->m))), d);
		}
		else if ((cone_intersect(d, d->cone[i]) && d->ray_dist < d->temp_dist && d->neg))
		{
			ITR(d->cone[i].col, vmul(vnorm(vsub(HP, d->nsphere.pos)), -1.0), d);
		}
	}
	i = -1;
	while (++i < d->info.cylinder_count)
	{
		temp = cylinder_intersect(d, d->cylinder[i]);
		if (temp > 0 && d->ray_dist < d->temp_dist)
		{
			if (temp == 2 || temp == 3)
				ITR(d->cylinder[i].col, vnorm(d->cylinder[i].dir), d);
			else if (temp == 3)
				ITR(d->cylinder[i].col, vnorm(vmul(d->cylinder[i].dir, -1.0)), d);
			else	
				ITR(d->cylinder[i].col, vnorm(vsub(vsub(HP, d->cylinder[i].pos),
				vmul(d->cylinder[i].dir, d->m))), d);
		}
	}
	i = -1;
	while (++i < 1)
		if (torus_intersect(d, d->torus) && d->ray_dist < d->temp_dist)
			{
			double k = vdot(vsub(HP, d->torus.pos), d->torus.dir);
    		t_vector A = vsub(HP, vmul(d->torus.dir, k));
   			double m = sqrt(d->torus.rin * d->torus.rin - k * k);
			ITR(d->torus.col, vnorm(
				vnorm(vmul(vsub(HP, vsub(A, vsub(d->torus.pos , A))), (m / (m + d->torus.rout))))
				), d);
			}
	// i = -1;
	// while (++i < 2)
	// 	if (cube_intersect(d, d->ncube) && d->ray_dist < d->temp_dist)
	// 		ITR(d->ncube.col, vnorm(vsub(HP, vinit(0.0, 0.0, 0.0))), d);
	if (d->temp_dist > d->ray.dist || d->temp_dist < 0.01)
		return (0);
	else
		return (1);
}

t_color	col_add(t_color col1, t_color col2)
{
	t_color	res;

	res.r = fmin(1.0, col1.r + col2.r);
	res.g = fmin(1.0, col1.g + col2.g);
	res.b = fmin(1.0, col1.b + col2.b);
	return (res);
}
