/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izelensk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 16:48:57 by izelensk          #+#    #+#             */
/*   Updated: 2017/07/07 16:48:59 by izelensk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vector	vinit(double x, double y, double z)
{
	t_vector	vec;

	vec.x = x;
	vec.y = y;
	vec.z = z;
	return (vec);
}

t_vector	vsub(t_vector v1, t_vector v2)
{
	v1.x -= v2.x;
	v1.y -= v2.y;
	v1.z -= v2.z;
	return (v1);
}

t_vector	vadd(t_vector v1, t_vector v2)
{
	v1.x += v2.x;
	v1.y += v2.y;
	v1.z += v2.z;
	return (v1);
}

t_vector	vmul(t_vector v1, double l)
{
	v1.x *= l;
	v1.y *= l;
	v1.z *= l;
	return (v1);
}

t_vector	vnorm(t_vector v1)
{
	double	length;

	length = vlen(v1);
	v1.x /= length;
	v1.y /= length;
	v1.z /= length;
	return (v1);
}
