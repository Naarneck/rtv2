/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_objects.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izelensk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 19:07:19 by izelensk          #+#    #+#             */
/*   Updated: 2017/07/07 19:07:22 by izelensk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_sphere	init_sphere(t_vector pos, double radius, t_color col)
{
	t_sphere sphere;

	sphere.pos.x = pos.x;
	sphere.pos.y = pos.y;
	sphere.pos.z = pos.z;
	sphere.radius = radius;
	sphere.col.r = col.r;
	sphere.col.g = col.g;
	sphere.col.b = col.b;
	return (sphere);
}

t_cylinder	init_cylinder(t_vector pos, t_vector dir, double r, t_color c)
{
	t_cylinder cylinder;

	cylinder.pos.x = pos.x;
	cylinder.pos.y = pos.y;
	cylinder.pos.z = pos.z;
	cylinder.dir.x = dir.x;
	cylinder.dir.y = dir.y;
	cylinder.dir.z = dir.z;
	cylinder.radius = r;
	cylinder.col.r = c.r;
	cylinder.col.g = c.g;
	cylinder.col.b = c.b;
	return (cylinder);
}

t_cone		init_cone(t_vector pos, t_vector dir, double angle, t_color c)
{
	t_cone cone;

	cone.pos.x = pos.x;
	cone.pos.y = pos.y;
	cone.pos.z = pos.z;
	cone.dir.x = dir.x;
	cone.dir.y = dir.y;
	cone.dir.z = dir.z;
	cone.angle = angle;
	cone.col.r = c.r;
	cone.col.g = c.g;
	cone.col.b = c.b;
	return (cone);
}

t_torus			init_torus(t_vector pos, t_vector dir, double rout, double rin, t_color c)
{
	t_torus torus;

	torus.pos.x = pos.x;
	torus.pos.y = pos.y;
	torus.pos.z = pos.z;
	torus.dir.x = dir.x;
	torus.dir.y = dir.y;
	torus.dir.z = dir.z;
	torus.rout = rout;
	torus.rin = rin;
	torus.col.r = c.r;
	torus.col.g = c.g;
	torus.col.b = c.b;
	return (torus);
}

t_plane		init_plane(t_vector point, t_vector normal, t_color col)
{
	t_plane plane;

	plane.point.x = point.x;
	plane.point.y = point.y;
	plane.point.z = point.z;
	plane.normal.x = normal.x;
	plane.normal.y = normal.y;
	plane.normal.z = normal.z;
	plane.col.r = col.r;
	plane.col.g = col.g;
	plane.col.b = col.b;
	return (plane);
}

t_light		init_light(t_vector pos, t_color col)
{
	t_light light;

	light.pos.x = pos.x;
	light.pos.y = pos.y;
	light.pos.z = pos.z;
	light.col.r = col.r;
	light.col.g = col.g;
	light.col.b = col.b;
	return (light);
}


t_cube	init_cube(t_vector pos, t_vector dir, double l, t_color col)
{
	t_cube cube;
	double angle_x;
	double angle_y;

	angle_x = ACOSN(dir.x / vlen(dir));
	angle_y = ACOSN(dir.y / vlen(dir));
	cube.p1 = vinit(l, l, l);
	cube.p2 = vinit(l, l, -l);
	cube.p3 = vinit(l, -l, l);
	cube.p4 = vinit(l, -l, -l);
	cube.p5 = vinit(-l, l, l);
	cube.p6 = vinit(-l, l, -l);
	cube.p7 = vinit(-l, -l, l);
	cube.p8 = vinit(-l, -l, -l);
	cube.p1 = rotatey(rotatex(cube.p1, angle_x), angle_y);
	cube.p2 = rotatey(rotatex(cube.p2, angle_x), angle_y);
	cube.p3 = rotatey(rotatex(cube.p3, angle_x), angle_y);
	cube.p4 = rotatey(rotatex(cube.p4, angle_x), angle_y);
	cube.p5 = rotatey(rotatex(cube.p5, angle_x), angle_y);
	cube.p6 = rotatey(rotatex(cube.p6, angle_x), angle_y);
	cube.p7 = rotatey(rotatex(cube.p7, angle_x), angle_y);
	cube.p8 = rotatey(rotatex(cube.p8, angle_x), angle_y);
	cube.p1 = vinit(cube.p1.x + pos.x, cube.p1.y + pos.y, cube.p1.z + pos.z);
	cube.p2 = vinit(cube.p2.x + pos.x, cube.p2.y + pos.y, cube.p2.z + pos.z);
	cube.p3 = vinit(cube.p3.x + pos.x, cube.p3.y + pos.y, cube.p3.z + pos.z);
	cube.p4 = vinit(cube.p4.x + pos.x, cube.p4.y + pos.y, cube.p4.z + pos.z);
	cube.p5 = vinit(cube.p5.x + pos.x, cube.p5.y + pos.y, cube.p5.z + pos.z);
	cube.p6 = vinit(cube.p6.x + pos.x, cube.p6.y + pos.y, cube.p6.z + pos.z);
	cube.p7 = vinit(cube.p7.x + pos.x, cube.p7.y + pos.y, cube.p7.z + pos.z);
	cube.p8 = vinit(cube.p8.x + pos.x, cube.p8.y + pos.y, cube.p8.z + pos.z);
	cube.col.r = col.r;
	cube.col.g = col.g;
	cube.col.b = col.b;	
	return (cube);
}
// t_cube	init_cube(t_vector pos, t_vector dir, double edge, t_color col)
// {
// 	t_cube cube;

// 	cube.pos.x = pos.x;
// 	cube.pos.y = pos.y;
// 	cube.pos.z = pos.z;
// 	cube.dir.x = dir.x;
// 	cube.dir.y = dir.y;
// 	cube.dir.z = dir.z;
// 	coube.edge = edge;
// 	cube.col.r = col.r;
// 	cube.col.g = col.g;
// 	cube.col.b = col.b;

// 	return (cube);
// }
