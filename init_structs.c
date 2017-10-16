/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izelensk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 19:07:32 by izelensk          #+#    #+#             */
/*   Updated: 2017/07/07 19:07:34 by izelensk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_cam		init_cam(t_vector pos, t_vector dir, double fov)
{
	t_cam cam;

	cam.dir.x = dir.x;
	cam.dir.y = dir.y;
	cam.dir.z = dir.z;
	cam.pos.x = pos.x;
	cam.pos.y = pos.y;
	cam.pos.z = pos.z;
	cam.fov = fov;
	return (cam);
}

t_color		init_color(double r, double g, double b)
{
	t_color color;

	color.r = fmin(1.0, r);
	color.g = fmin(1.0, g);
	color.b = fmin(1.0, b);
	return (color);
}

t_ray		init_ray(t_vector origin, t_vector dir, double dist)
{
	t_ray	ray;

	ray.origin.x = origin.x;
	ray.origin.y = origin.y;
	ray.origin.z = origin.z;
	ray.dir.x = dir.x;
	ray.dir.y = dir.y;
	ray.dir.z = dir.z;
	ray.dist = dist;
	return (ray);
}

double		vdot(t_vector v1, t_vector v2)
{
	return ((v1.x * v2.x) + (v1.y * v2.y) + (v1.z * v2.z));
}

double		vlen(t_vector v1)
{
	return (sqrt((v1.x * v1.x) + (v1.y * v1.y) + (v1.z * v1.z)));
}
