/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izelensk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 16:49:06 by izelensk          #+#    #+#             */
/*   Updated: 2017/07/07 16:49:08 by izelensk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_color		col_norm(int col)
{
	t_color res;

	res.b = (double)(col & 0x0000ff) / 255.0;
	res.g = (double)((col >> 8) & 0x0000ff) / 255.0;
	res.r = (double)(col >> 16) / 255.0;
	return (res);
}

t_color		col_mult(t_color col1, t_color col2)
{
	t_color	res;

	res.r = fmin(1.0, col1.r * col2.r);
	res.g = fmin(1.0, col1.g * col2.g);
	res.b = fmin(1.0, col1.b * col2.b);
	return (res);
}

t_color		col_mult_d(t_color col1, double d)
{
	t_color	res;

	res.r = fmin(1.0, col1.r * d);
	res.g = fmin(1.0, col1.g * d);
	res.b = fmin(1.0, col1.b * d);
	return (res);
}

t_color		col_avg(t_color col1, t_color col2)
{
	t_color	res;

	res.r = fmin(1.0, (col1.r + col2.r) / 2.0);
	res.g = fmin(1.0, (col1.g + col2.g) / 2.0);
	res.b = fmin(1.0, (col1.b + col2.b) / 2.0);
	return (res);
}

t_color		col_clamp(t_color col1)
{
	t_color	res;

	res.r = fmin(1.0, col1.r);
	res.g = fmin(1.0, col1.g);
	res.b = fmin(1.0, col1.b);
	res.r = fmax(0.0, col1.r);
	res.g = fmax(0.0, col1.g);
	res.b = fmax(0.0, col1.b);
	return (res);
}

t_color		col_mix(t_color base, t_color col2) // test
{
	t_color	res;

	res.r = col2.r + ((base.r - col2.r) / 2.0);
	res.g = col2.g + ((base.g - col2.g) / 2.0);
	res.b = col2.b + ((base.b - col2.b) / 2.0);
	return (res);
}
