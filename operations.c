/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izelensk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 17:42:50 by izelensk          #+#    #+#             */
/*   Updated: 2017/06/01 17:42:53 by izelensk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int			ft_atoi_hex(char *str)
{
	int		i;
	int		n;

	n = 0;
	i = 0;
	while (str[i] != '\0' && str[i] != ' ' && str[i] != '\n')
	{
		if (n > 0xffffff)
			return (0xffffff);
		if (str[i] >= '0' && str[i] <= '9')
			n = (n * 16) + (str[i] - '0');
		else if (str[i] >= 'a' && str[i] <= 'f')
			n = (n * 16) + (str[i] - 'a' + 10);
		else if (str[i] >= 'A' && str[i] <= 'F')
			n = (n * 16) + (str[i] - 'A' + 10);
		i++;
	}
	return (n);
}

double		ft_atof(char *str)
{
	int		i;
	double	n;
	int		div_part;
	int		mod_part;
	char	*temp;

	i = 0;
	n = 0.0;
	while (str[i] != '.' && str[i] != ' ' && str[i] != '\0' && str[i] != '\n')
		i++;
	temp = ft_strsub(str, 0, i);
	div_part = ft_atoi(temp);
	n += (double)div_part;
	free(temp);
	temp = ft_strsub(str, i + 1, ft_strlen(str) - i);
	mod_part = ft_atoi(temp);
	if (div_part > 0)
		n += pow(0.1, ft_strlen(str) - i - 1) * (double)mod_part;
	else
		n -= pow(0.1, ft_strlen(str) - i - 1) * (double)mod_part;
	free(temp);
	return (n);
}

double		quad_equation_t1(double a, double b, double c)
{
	if ((b * b - 4.0 * a * c) >= 0)
		return ((-b + sqrt(b * b - 4.0 * a * c)) / (2.0 * a));
	else
		return (10001.0);
}

double		quad_equation_t2(double a, double b, double c)
{
	if ((b * b - 4.0 * a * c) >= 0.0)
		return ((-b - sqrt(b * b - 4 * a * c)) / (2.0 * a));
	else
		return (10001.0);
}

t_color		norm_hex(int col)
{
	t_color	res;

	res.r = (double)(col >> 16) / 255.0;
	res.g = (double)((col >> 8) & 0xff) / 255.0;
	res.b = (double)(col & 0x0000ff) / 255.0;
	return (res);
}

// double *solve_cubic_a(double a, double b, double c, double d)
// {
// 	double disc, q, r, dum1, s, t, term1, r13;
// 	double *x;

// 	x = (double *)malloc(sizeof(double) * 3);
// 	x[0] = 0.0;
// 	x[1] = 0.0;
// 	x[2] = 0.0;
// 	if (a == 0)
// 	{
// 		printf("The coefficient of the cube of x is 0. Please use the utility for a SECOND degree quadratic. No further action taken.\n");
// 		return (x);
// 	} //End if a == 0

// 	if (d == 0)
// 	{
// 		printf("One root is 0. Now divide through by x and use the utility for a SECOND degree quadratic to solve the resulting equation for the other two roots. No further action taken.\n");
// 		return (x);
// 	} //End if d == 0
// 	b /= a;
// 	c /= a;
// 	d /= a;

// 	q = (3.0 * c - (b * b)) / 9.0;
// 	r = -(27.0 * d) + b * (9.0 * c - 2.0 * (b * b));
// 	r /= 54.0;
// 	disc = q * q * q + r * r;
// 	term1 = (b / 3.0);
// 	if (disc > 0) 
// 	{ // one root real, two are complex
// 		s = r + sqrt(disc);
// 		s = ((s < 0) ? -pow(-s, (1.0 / 3.0)) : pow(s, (1.0 / 3.0)));
// 		t = r - sqrt(disc);
// 		t = ((t < 0) ? -pow(-t, (1.0 / 3.0)) : pow(t, (1.0 / 3.0)));
		
// 		x[1] = -term1 + s + t; //root 1
// 		term1 += (s + t)/2.0;
// 		// dataForm.x3Re.value = dataForm.x2Re.value = -term1;
// 		term1 = sqrt(3.0) * (-t + s)/2;
// 		x[2] = term1; //root 2 
// 		x[3] = -term1; //root 3
// 		printf("disc > 0\n" );
// 		return (x);
// 	} 
// 	// End if (disc > 0)
// 	// The remaining options are all real
// 	if (disc == 0)
// 	{ // All roots real, at least two are equal.
// 		r13 = ((r < 0) ? pow(-r, (1.0 / 3.0)) : pow(r, (1.0 / 3.0)));
// 		x[1] = -term1 + 2.0 * r13;
// 		x[2] = -(r13 + term1);
// 		x[3] = x[2];
// 		printf("disc = 0\n" );
// 		return (x);
// 	} // End if (disc == 0)
// 	// Only option left is that all roots are real and unequal (to get here, q < 0)
// 	q = -q;
// 	dum1 = q * q * q;
// 	dum1 = acos(r / sqrt(dum1));
// 	r13 = 2.0 * sqrt(q);
// 	x[1] = -term1 + r13 * cos(dum1 / 3.0); //x1
// 	x[2] = -term1 + r13 * cos((dum1 + 2.0 * PI) / 3.0); //x2
// 	x[3] = -term1 + r13 * cos((dum1 + 4.0 * PI) / 3.0); //x3
// 	printf("disc < 0\n" );
// 	return (x);
// }  //End of cubicSolve


// double *solve_quartic(double a, double b, double c, double d, double e)
// {
// 	double i, j, k, r, s, q, p;
// 	double u[4];
// 	double *x, *z;

// 	x = (double *)malloc(sizeof(double) * 4);
// 	x[0] = -1.0;
// 	x[1] = -1.0;
// 	x[2] = -1.0;
// 	x[3] = -1.0;
// 	// ax^4 + bx^3 + cx^2 + dx + e = 0 (=) Divide by a
// 	// x^4 + Bx^3 + Cx^2 + Dx + E = 0
// 	// B = b/a
// 	// C = c/a
// 	// D = d/a
// 	// E = e/a
// 	b /= a;
// 	c /= a;
// 	d /= a;
// 	e /= a;
	
// 	//(depressed quartic, like in Ferrari's method)
// // alpha = I = -3(B^2) / 8 + C
// // beta = J = (B^3)/8 - BC/2 + D
// // gamma = K = -3(B^4)/256 + C(B^2)/16 - BD/4 + E	
// 	i = (-3.0 * (b * b)) / 8 + c;
// 	j = (pow(b, 3.0)) / 8 - (b * c) / 2 + d;
// 	k = (-3.0 * (pow(b, 4.0)) / 256.0) + (c * (b * b) / 16.0) - ((b * d) / 4.0) + e;
// 	// Solve equation for z (one solution is enough):
// 	// z^3 + 2Iz^2 + (I^2 - 4K)z - J^2 = 0
// 	printf("a: %f b: %f c: %f d: %f\n", 1.0, 2 * i, (i * i - 4.0 * k), j * j);
// 	z = solve_cubic(1.0, 2 * i, (i * i - 4.0 * k), j * j);
// 	// if (z < 0.0)
// 	// 	return (x);
// 	printf("z1: %f z2: %f z3: %f\n", x[0], x[1], x[2]);
// 	p = sqrt(z[0]);
// 	r = -p;
// 	q = (i + z[0] - (j / p)) / 2;
// 	s = (i + z[0] + (j / p)) / 2;
// 	//Solve (there are four u's, two for each equation):
// 	// u^2 + pu + q = 0
// 	// u^2 + ru + s = 0

// 	u[0] = quad_equation_t1(1.0, p, q);
// 	u[1] = quad_equation_t2(1.0, p, q);
// 	u[2] = quad_equation_t1(1.0, r, s);
// 	u[3] = quad_equation_t2(1.0, r, s);
// 	// Solution (x[]):
// 	// for each root u[i], x[i] = u[i] - B/4
// 	x[0] = u[0] - b / 4;
// 	x[1] = u[1] - b / 4;
// 	x[2] = u[2] - b / 4;
// 	x[3] = u[3] - b / 4;
// 	//printf("x1: %f x2: %f x3: %f x4 %f\n", x[0], x[1], x[2], x[3]);
// 	return (x);
// }

// int main(int argc, char const *argv[])
// {

// 	printf("one of root is: %f\n",  solve_cubic(1.0, -7.0, 4.0, 12.0));
// 	solve_quartic(16.0, 96.0, -24.0, -664.0, -315.0);
// 	return 0;
// }


// #include <math.h>
// #include <stdio.h>
// #include <stdlib.h>

// #define INF 1e300
// #define EPS 1e-4


t_complex		sqrt_complex(t_complex c)
{
	t_complex res;
	
	double k = sqrt(c.Re * c.Re + c.Im * c.Im);
	res.Re = sqrt((k + c.Re) * 0.5);
	res.Im = ((c.Im > 0) ? 1 : -1) * sqrt((k - c.Re) * 0.5);
	return res;
}

double			find_right_root_(int n_roots, double *roots)
{
	double res = -1;
	double min_res = INF;

	int i = -1;
	while (++i < n_roots)
	{
		if (roots[i] > 0 && roots[i] < min_res)
		{
			res = roots[i];
			min_res = res;
		}
	}
	return res;
}

double			find_right_root(int n_roots, t_complex *roots)
{
	double res = -1.0;

	int i = -1;
	while (++i < n_roots)
	{
		if (roots[i].Re > 0 && roots[i].Re > res)
			res = roots[i].Re;
	}
	return res;
}

void			double_swap(double *a, double *b)
{
	double tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int		solve_quadratic(double a, double b, double c, t_complex **roots)
{
	double d;
	double sol;

	d = b * b - 4 * a * c;
	if (d < 0)
		return 0;
	else if (d == 0)
	{
		(*roots) = (t_complex*)malloc(sizeof(t_complex));
		(*roots)[0].Re = -0.5 * b / a;
		return 1;
	}
	else
	{
		(*roots) = (t_complex*)malloc(sizeof(t_complex) * 2);
		sol = (b > 0) ? -0.5 * (b + sqrt(d)) : -0.5 * (b - sqrt(d));
		(*roots)[0].Re = sol / a;
		(*roots)[1].Re = c / sol;
		if ((*roots)[0].Re > (*roots)[1].Re)
			double_swap(&(*roots)[0].Re, &(*roots)[1].Re);
		return 2;
	}
}

int		solve_cubic(double b, double c, double d, t_complex **roots)
{
    if (d == 0)
    	return (solve_quadratic(1, b, c, roots));
    (*roots) = (t_complex*)malloc(sizeof(t_complex) * 3);
    double disc, q, r, dum1, s, t, term1, r13;

    q = (3.0 * c - (b * b)) / 9.0;
    r = -(27.0 * d) + b * (9.0 * c - 2.0 * (b * b));
    r /= 54.0;
    disc = q * q * q + r * r;
    (*roots)[0].Im = 0;
    term1 = (b / 3.0);
    if (disc > 0)
    {
        s = r + sqrt(disc);
        s = ((s < 0) ? -pow(-s, (1.0 / 3.0)) : pow(s, (1.0 / 3.0)));
        t = r - sqrt(disc);
        t = ((t < 0) ? -pow(-t, (1.0 / 3.0)) : pow(t, (1.0 / 3.0)));
        (*roots)[0].Re = -term1 + s + t;
        term1 += (s + t)/2.0;
        (*roots)[2].Re = (*roots)[1].Re = -term1;
        term1 = sqrt(3.0) * (-t + s) / 2;
        (*roots)[1].Im = term1;
        (*roots)[2].Im = -term1;
        return 1;
    } 
    (*roots)[2].Im = (*roots)[1].Im = 0;
    if (disc == 0)
    {
        r13 = ((r < 0) ? -pow(-r, (1.0 / 3.0)) : pow(r, (1.0 / 3.0)));
        (*roots)[0].Re = -term1 + 2.0 * r13;
        (*roots)[2].Re = (*roots)[1].Re = -(r13 + term1);
        return 2;
    }
    q = -q;
    dum1 = q * q * q;
    dum1 = acos(r / sqrt(dum1));
    r13 = 2.0 * sqrt(q);
    (*roots)[0].Re = -term1 + r13 * cos(dum1 / 3.0);
    (*roots)[1].Re = -term1 + r13 * cos((dum1 + 2.0 * M_PI) / 3.0);
    (*roots)[2].Re = -term1 + r13 * cos((dum1 + 4.0 * M_PI) / 3.0);
    return 3;
}

int		solve_quartic(double b, double c, double d, double e, double **roots)
{
	double f, g, h;
	t_complex	*cubic_roots;

	f = c - b * b * 0.375;
	g = d + b * b * b * 0.125 - b * c * 0.5;
	h = e - 3 * b * b * b * b / 256 + b * b * c / 16 - b * d * 0.25;
	// printf("f = %f\ng = %f\nh = %f\n", f, g, h);
	int	n_cubic_roots;

	n_cubic_roots = solve_cubic(f * 0.5, (f * f - 4 * h) / 16.0, -g * g / 64.0, &cubic_roots);
	// printf("n_cubic_roots = %d\n", n_cubic_roots);
	if (n_cubic_roots == 1)
	{
		t_complex p, q;
		double r, s;
		p = sqrt_complex(cubic_roots[1]);
		q = sqrt_complex(cubic_roots[2]);
		r = -g / (8 * (p.Re * p.Re + p.Im * p.Im));
		s = b * 0.25;
		// printf("p = %f + i%f\nq = %f + i%f\nr = %f\ns = %f\n", p.Re, p.Im, q.Re, q.Im, r, s);
		(*roots) = (double*)malloc(sizeof(double) * 2);
		(*roots)[0] = p.Re + q.Re + r - s;
		(*roots)[1] = -p.Re - q.Re + r - s;
		return 2;
	}
	else if (n_cubic_roots == 2 || n_cubic_roots == 3)
	{
		double r, s, p, q;
		if (n_cubic_roots == 2)
		{
			p = sqrt(cubic_roots[0].Re);
			q = sqrt(cubic_roots[1].Re);
			r = -g / (8 * p * q);
			s = b  * 0.25;
		}
		else
		{
			p = (cubic_roots[0].Re > 0.0) ?  sqrt(cubic_roots[0].Re) : sqrt(cubic_roots[1].Re);
			if (cubic_roots[0].Re <= 0.0)
				q = sqrt(cubic_roots[2].Re);
			else
				q = sqrt(cubic_roots[1].Re);
			r = -g / (8 * p * q);
			s = b  * 0.25;
		}
		(*roots) = (double*)malloc(sizeof(double) * 4);
		(*roots)[0] = p + q + r - s;
		(*roots)[1] = p - q - r - s;
		(*roots)[2] = -p + q - r - s;
		(*roots)[3] = -p - q + r - s;
		return (4);
	}
	else
		return (0);

}

int		main(int ac, char **av)
{
	double		*roots;
	int			n_roots;

	if (ac != 6)
		return (1);
	double a = atof(av[1]), b = atof(av[2]), c = atof(av[3]), d = atof(av[4]), e = atof(av[5]);
	a = 1.0 / a;
	n_roots = solve_quartic(b * a, c * a, d * a, e * a, &roots);
	if (n_roots == 0)
		printf("No roots\n");
	else
	{
		int i = -1;
		double result = -1.0;
		double min_res = INF;
		while (++i < n_roots)
		{
			if (roots[i] > 0 && roots[i] < min_res)
			{
				result = roots[i];
				min_res = result;
			}
			printf("root_%d = %f\n", i, roots[i]);
		}
		printf("resulted root = %f\n", result);
	}
	return (0);
}