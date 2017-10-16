/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izelensk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 16:48:42 by izelensk          #+#    #+#             */
/*   Updated: 2017/07/07 16:48:44 by izelensk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#define HP vadd(d->ray.origin, vmul(d->ray.dir, d->ray_dist))
#define	CH 5.0

int		sphere_intersect(t_data *d, t_sphere sphere)
{
	t_vector x_omc;

	x_omc = vsub(d->ray.origin, sphere.pos);
	d->a = vdot(d->ray.dir, d->ray.dir);
	d->b = 2.0 * vdot(d->ray.dir, x_omc);
	d->c = vdot(x_omc, x_omc) - sphere.radius * sphere.radius;
	d->t1 = quad_equation_t1(d->a, d->b, d->c);
	d->t2 = quad_equation_t2(d->a, d->b, d->c);
	d->ray_dist = d->t1;
	if (d->t2 <= d->t1)
		d->ray_dist = d->t2;
	if ((d->ray_dist > 0.00001f) && (d->ray_dist <= d->ray.dist))
		return (1);
	else
		return (0);
}

int		plane_intersect_(t_data *d, t_plane plane)
{
	d->t1 = 0.0;
	if (fabs(vdot(d->ray.dir, plane.normal)) >= 0.01f)
		d->t1 = (vdot(vmul(vsub(d->ray.origin, plane.point), -1.0),	plane.normal)) / vdot(d->ray.dir, plane.normal);
	else
		d->t1 = -42.0;
	d->ray_dist = d->t1;
	if (d->t1 > 0.01f && d->t1 <= d->ray.dist)
		return (1);
	else
		return (0);
}

int		plane_intersect(t_data *d, t_plane plane)
{
	d->t1 = 0.0;
	if (fabs(vdot(d->ray.dir, plane.normal)) >= 0.01f)
		d->t1 = (vdot(vmul(vsub(d->ray.origin, plane.point), -1.0),
		plane.normal)) / vdot(d->ray.dir, plane.normal);
	else
		d->t1 = -42.0;
	d->ray_dist = d->t1;
	if (d->t1 > 0.01f && d->ray_dist <= d->ray.dist)
		return (1);
	else
		return (0);
}

int		disc_intersect(t_data *d, t_plane plane, double r)
{
	d->t1 = 0.0;
	if (fabs(vdot(d->ray.dir, plane.normal)) >= 0.01f)
		d->t1 = (vdot(vmul(vsub(d->ray.origin, plane.point), -1.0),
		plane.normal)) / vdot(d->ray.dir, plane.normal);
	else
		d->t1 = -42.0;
	d->ray_dist = d->t1;
	if (vlen(vsub(HP , plane.point)) > r)
		return (0);
	if (d->t1 > 0.01f && d->ray_dist <= d->ray.dist)
		return (1);
	else
		return (0);
}

int		cylinder_intersect(t_data *d, t_cylinder cylinder)
{
	double		dv;
	t_vector	x_omc;
	// double		ch;
	// double		php;
	t_plane		cap1;
	t_plane		cap2;

	cap1 = init_plane(cylinder.pos, vmul(cylinder.dir , -1.0), cylinder.col);
	cap2 = init_plane(vadd(cylinder.pos, vmul(cylinder.dir, CH)), cylinder.dir, cylinder.col);
	x_omc = vsub(d->ray.origin, cylinder.pos);
	dv = vdot(d->ray.dir, cylinder.dir);
	d->a = vdot(d->ray.dir, d->ray.dir) - (dv * dv);
	d->b = 2.0 * (vdot(d->ray.dir, x_omc) - dv * vdot(x_omc, cylinder.dir));
	d->c = vdot(x_omc, x_omc) - (vdot(x_omc, cylinder.dir) * vdot(x_omc,
	cylinder.dir)) - (cylinder.radius * cylinder.radius);
	d->t1 = quad_equation_t1(d->a, d->b, d->c);
	d->t2 = quad_equation_t2(d->a, d->b, d->c);
	d->ray_dist = d->t1;

	if (fabs(d->t2) <= fabs(d->t1))
		d->ray_dist = d->t2;
	// php = vlen(vsub(HP, cylinder.pos));
	// ch = sqrt(php * php - cylinder.radius * cylinder.radius);
	d->m = dv * d->ray_dist + vdot(x_omc, cylinder.dir);
	// if (disc_intersect(d, cap1, cylinder.radius))
	// 	return (1);
	if (d->ray_dist > 0.01f && d->ray_dist <= d->ray.dist && d->m < CH && d->m > 0.0)
	{
		return (1);
	}
	else if (disc_intersect(d, cap1, cylinder.radius))
	{
		return (2);
	}
	else if (disc_intersect(d, cap2, cylinder.radius))
	{
		return (2);
	}
	else
		return (0);
}

int		cylinder_intersect_inf(t_data *d, t_cylinder cylinder)
{
	double		dv;
	t_vector	x_omc;

	x_omc = vsub(d->ray.origin, cylinder.pos);
	dv = vdot(d->ray.dir, cylinder.dir);
	d->a = vdot(d->ray.dir, d->ray.dir) - (dv * dv);
	d->b = 2.0 * (vdot(d->ray.dir, x_omc) - dv * vdot(x_omc, cylinder.dir));
	d->c = vdot(x_omc, x_omc) - (vdot(x_omc, cylinder.dir) * vdot(x_omc,
	cylinder.dir)) - (cylinder.radius * cylinder.radius);
	d->t1 = quad_equation_t1(d->a, d->b, d->c);
	d->t2 = quad_equation_t2(d->a, d->b, d->c);
	d->ray_dist = d->t1;
	if (fabs(d->t2) <= fabs(d->t1))
		d->ray_dist = d->t2;
	if (d->ray_dist > 0.01f && d->ray_dist <= d->ray.dist)
	{
		d->m = dv * d->ray_dist + vdot(x_omc, cylinder.dir);
		return (1);
	}
	else
		return (0);
}
/// T1    t1 T2  t2
int		cone_intersect(t_data *d, t_cone cone)
{
	double		dv;
	t_vector	x_omc;
	double T1;
	double T2;

	x_omc = vsub(d->ray.origin, cone.pos);
	dv = vdot(d->ray.dir, cone.dir);
	d->a = vdot(d->ray.dir, d->ray.dir) - (1.0 + cone.angle * cone.angle)
	* (dv * dv);
	d->b = 2.0 * (vdot(d->ray.dir, x_omc) - (1.0 + cone.angle * cone.angle)
	* dv * vdot(x_omc, cone.dir));
	d->c = vdot(x_omc, x_omc) - (1.0 + cone.angle * cone.angle) * vdot(x_omc,
	cone.dir) * vdot(x_omc, cone.dir);
	d->t1 = quad_equation_t1(d->a, d->b, d->c);
	d->t2 = quad_equation_t2(d->a, d->b, d->c);
	T1 = d->t1;
	T2 = d->t2;
	// if (1)
	// {
	// 	cylinder_intersect_inf(d, d->ncyl);
	// 	//sphere_intersect(d, d->nsphere);
	// 	if (T1 > d->t1 && d->t1 > T2 && T2 > d->t2)
	// 	{
	// 		T2 = d->t1;
	// 		d->neg = 1;	
	// 	}
	// 	else if (d->t1 > T1 && T1 > d->t2 && T2 > d->t2)
	// 		return (0);
	// }
	d->ray_dist = T1;
	if (fabs(T2) <= fabs(T1) && T2 > 0.01f)
		d->ray_dist = T2;	
	if (d->ray_dist > 0.01f && d->ray_dist <= d->ray.dist)
	{
		d->m = dv * d->ray_dist + vdot(x_omc, cone.dir);
		return (1);
	}
	return (0);
}

// int		triangle_intersect(t_data *d, t_tria tria)
// {
// 	t_vector v1;
// 	t_vector v2;
// 	t_vector	x_omc;

// 	x_omc = vsub(d->ray.origin, cone.pos);
// 	v1 = vsub(c1, c);
// 	v2 = vsub(c2, c);

// 	d->t1 = vdot(x, tria.norm) * -1.0 / vdot(d->ray.dir, tria.norm);
	
// }

int 	cube_intersect(t_data *d, t_cube cube)
{
	if (sphere_intersect(d, init_sphere(cube.p1, 1.0, cube.col)))
		return (1);
	else if (sphere_intersect(d, init_sphere(cube.p2, 1.0, cube.col)))
		return (1);
	else if (sphere_intersect(d, init_sphere(cube.p3, 1.0, cube.col)))
		return (1);
	else if (sphere_intersect(d, init_sphere(cube.p4, 1.0, cube.col)))
		return (1);
	else if (sphere_intersect(d, init_sphere(cube.p5, 1.0, cube.col)))
		return (1);
	else if (sphere_intersect(d, init_sphere(cube.p6, 1.0, cube.col)))
		return (1);
	else if (sphere_intersect(d, init_sphere(cube.p7, 1.0, cube.col)))
		return (1);
	else if (sphere_intersect(d, init_sphere(cube.p8, 1.0, cube.col)))
		return (1);
	return (0);
}

int		torus_intersect(t_data *f, t_torus torus)
{
	double	  n, o, p, q;
	// t_vector  q;
	// double	*t;
	double		*roots;
	int			n_roots;
// m = D|D, n = D|X, o = X|X, p = D|V, q = X|V where O is the ray origin and D is the ray direction. where C is a center point of a shape that we hit and X equals O-C.
	// x_omc = vsub(f->ray.origin, torus.pos); //q
	// m = vdot(f->ray.dir, f->ray.dir); //1.0 
	// n = vdot(f->ray.dir, x_omc);			
	// o = vdot(x_omc, x_omc);					
	// p = vdot(f->ray.dir, torus.dir);		 //v
	// q = vdot(x_omc, torus.dir);				
	// a = 1.0 / (m * m);
	// t = solve_quartic(
	// 	m * m,
	// 	4.0 * m * n,
	// 	4.0 * m * m + (2.0 * m * o) - 2.0 * ((torus.rout * torus.rout) + (torus.rin * torus.rin)) * m + 4.0 * torus.rout * torus.rout * p * p,
	// 	4.0 * n * o - 4.0 * ((torus.rout * torus.rout) + (torus.rin * torus.rin)) * n + 8.0 * torus.rout * torus.rout * p * q,
	// 	o * o - 2.0 * ((torus.rout * torus.rout) + (torus.rin * torus.rin)) * o + 4.0 * torus.rout * torus.rout * q * q + pow(((torus.rout * torus.rout) - (torus.rin * torus.rin)), 2.0)
	// );
	// a = m^2
   // b = 4*m*n
   // c = 4*m^2 + 2*m*o - 2*(R^2+r^2)*m + 4*R^2*p^2
   // d = 4*n*o - 4*(R^2+r^2)*n + 8*R^2*p*q
   // e = o^2 - 2*(R^2+r^2)*o + 4*R^2*q^2 + (R^2-r^2)^2
	// double  a, u, v, b, c, d;
	
	// q = vsub(f->ray.origin, torus.pos);
	// u = vdot(torus.dir, q);
	// v = vdot(torus.dir, f->ray.dir);
	// d = vdot(q, q) + torus.rout * torus.rout - torus.rin * torus.rin;
	// a = (vdot(f->ray.origin, f->ray.dir) - v * v);
	// b = 2.0 * (vdot(q, f->ray.dir) - u * v);
	// c = vdot(q, q) - u * u;
	 
	t_vector x = vsub(f->ray.origin, torus.pos);
    n = vdot(f->ray.dir, x);
    o = vdot(x, x);
    p = vdot(f->ray.dir, torus.dir);
    q = vdot(x, torus.dir);
    double b, c, d, e;
    double d_ = vdot(x, x) + torus.rout * torus.rout - torus.rin * torus.rin;

	b = 4.0f * n;
    c = 2.0f * d_ + 0.25f * b * b - 4.0f * torus.rout * torus.rout * (1.0 - p * p);
    d = b * d_ - 4.0f * torus.rout * torus.rout * 2.0f * (n - q * p);
    e = d_ * d_ - 4.0f * torus.rout * torus.rout * (o - q * q);
	n_roots = solve_quartic(
		// a * (4.0 * m * n),//+
		// a * ((4.0 * m * m) + (2.0 * m * o) - (2.0 * m * ((torus.rout * torus.rout) - (torus.rin * torus.rin))) + (4.0 * (torus.rout * torus.rout) * (p * p))),
		// a * ((4.0 * n * o) - (4.0 * n * ((torus.rout * torus.rout) - (torus.rin * torus.rin))) + (8.0 * torus.rout * torus.rout * p * q)),
		// a * (o * o - (2.0 * o * ((torus.rout * torus.rout) - (torus.rin * torus.rin))) + (4.0 * (torus.rout * torus.rout) * (q * q))
		// 	+ pow(((torus.rout * torus.rout) - (torus.rin * torus.rin)), 2.0)),
		// 4.0 * vdot(q, f->ray.dir),
		// 2.0 * d + 0.25 * pow(4.0 * vdot(q, f->ray.dir), 2) - 4 * torus.rout* torus.rout * a,
		// d * vdot(q, f->ray.dir) - 4.0 * torus.rout * torus.rout * b,
		// d* d - (4.0 * torus.rout*torus.rout)* c,
		b,c,d,e,
		&roots
	);
	if (n_roots == 0)
		return (0);
	else
	{
		int i = -1;
		double result = -1.0;
		double min_res = 10000.0;
		while (++i < n_roots)
		{
			if (roots[i] > 0.1f && roots[i] < min_res)
			{
				result = roots[i];
				min_res = result;
			}
			// printf("root_%d = %f  ", i, roots[i]);
		}
		// printf("\n" );
		f->ray_dist = result;
		// printf("resulted root = %f\n", result);
	}
	// d->k
	// d->m =  = sqrt(torus.rin * torus.rin - k * k);
	if (f->ray_dist > 0.1 && f->ray_dist < f->ray.dist)
		return (1);
	// printf("x1: %f x2: %f x3: %f x4 %f\n", t[0], t[1], t[2], t[3]);	
	// f->ray_dist = t[0];
	// if (t[1] > 0.01f && t[1] < f->ray_dist)
	// 	f->ray_dist = t[1];
	// if (t[2] > 0.01f && t[2] < f->ray_dist)
	// 	f->ray_dist = t[2];
	// if (t[3] > 0.01f && t[3] < f->ray_dist)
	// 	f->ray_dist = t[3];
	// if (f->ray_dist > 0.01f && f->ray_dist <= f->ray.dist)
	// 	return (1);
	// else
	return (0);
}


