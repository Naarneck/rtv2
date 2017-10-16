/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izelensk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 19:11:03 by izelensk          #+#    #+#             */
/*   Updated: 2017/07/07 19:11:06 by izelensk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vector	rotatex(t_vector vec, double alpha)
{
	t_vector res;

	res.x = vec.x;
	res.y = (vec.y * COSN(alpha)) + (vec.z * SINS(alpha));
	res.z = ((-vec.y) * SINS(alpha)) + (vec.z * COSN(alpha));
	return (res);
}

t_vector	rotatey(t_vector vec, double alpha)
{
	t_vector res;

	res.x = (vec.x * COSN(alpha)) - (vec.z * SINS(alpha));
	res.y = vec.y;
	res.z = (vec.x * SINS(alpha)) + (vec.z * COSN(alpha));
	return (res);
}

t_vector	rotatez(t_vector vec, double alpha)
{
	t_vector res;

	res.x = (vec.x * COSN(alpha)) + (vec.y * SINS(alpha));
	res.y = (-vec.x * COSN(alpha)) + (vec.y * COSN(alpha));
	res.z = vec.z;
	return (res);
}
