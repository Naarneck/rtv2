/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izelensk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 13:31:46 by izelensk          #+#    #+#             */
/*   Updated: 2017/07/07 16:49:44 by izelensk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H
# include "mlx.h"
# include "libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include <time.h>


#include <stdio.h>

# define WIDTH 800
# define HEIGHT 800

# define PI 3.14159265
# define COSN(angle) cos(angle * PI / 180)
# define SINS(angle) sin(angle * PI / 180)
# define TANG(angle) tan(angle * PI / 180)
# define ACOSN(angle) acos(angle) * 180 / PI
# define POS(x, y) (x * 4 + y * d->size_line)

# define KEY_UP 13
# define KEY_DOWN 1
# define KEY_LEFT 0
# define KEY_RIGHT 2
# define KEY_AUP 126
# define KEY_ADOWN 125
# define KEY_ALEFT 123
# define KEY_ARIGHT 124
# define KEY_ESC 53
# define KEY_SPACE 49
# define KEY_ONE 18
# define KEY_TWO 19
# define KEY_THREE 20
# define KEY_FOUR 21
# define KEY_FIVE 23
# define KEY_SIX 22
# define KEY_SHIFT 257
# define KEY_CTRL 256
# define KEY_RSHIFT 258
# define KEY_RCTRL 269
# define KEY_PLUS 24
# define KEY_MINUS 27
# define KEY_Q 12
# define KEY_E 14
#define INF 1e300
#define EPS 1e-4

typedef struct		s_complex
{
	double Re, Im;
}					t_complex;

typedef	struct	s_info
{
	int			plane_count;
	int			sphere_count;
	int			cylinder_count;
	int			cone_count;
	int			light_count;
}				t_info;

typedef	struct	s_color
{
	double		r;
	double		g;
	double		b;
}				t_color;

typedef	struct	s_vector
{
	double		x;
	double		y;
	double		z;
}				t_vector;

typedef	struct	s_ires
{
	double		dist;
	t_vector	normal;
	t_color		color;
}				t_ires;

typedef	struct	s_cam
{
	t_vector	dir;
	t_vector	pos;
	double		fov;
}				t_cam;

typedef	struct	s_torus
{
	t_vector	pos;
	t_vector	dir;
	double		rin;
	double		rout;
	t_color		col;
}				t_torus;

typedef	struct	s_ray
{
	t_vector	origin;
	t_vector	dir;
	double		dist;
}				t_ray;


typedef	struct	s_cube
{
	t_vector	p1;
	t_vector	p2;
	t_vector	p3;
	t_vector	p4;
	t_vector	p5;
	t_vector	p6;
	t_vector	p7;
	t_vector	p8;
	t_color 	col;
}				t_cube;	


// typedef	struct	s_cube
// {
// 	t_vector	pos;
// 	t_vector	dir;
// 	double 		edge;
// 	t_color		col;
// }				t_cube;	

typedef	struct	s_sphere
{
	t_vector	pos;
	double		radius;
	t_color		col;
}				t_sphere;

typedef	struct	s_cylinder
{
	t_vector	pos;
	t_vector	dir;
	double		radius;
	t_color		col;
}				t_cylinder;

typedef	struct	s_tria
{
	t_vector	c;
	t_vector	norm;
	t_vector	c1;
	t_vector	c2;
}				t_tria;


typedef	struct	s_cone
{
	t_vector	pos;
	t_vector	dir;
	double		angle;
	t_color		col;
}				t_cone;

typedef	struct	s_plane
{
	t_vector	normal;
	t_vector	point;
	t_color		col;
}				t_plane;

typedef	struct	s_light
{
	t_vector	pos;
	t_color		col;
}				t_light;

typedef	struct	s_data
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*ptr;
	int			bpp;
	int			size_line;
	int			endian;
	int			temp;
	double		temp_dist;
	t_color		temp_color;
	t_vector	temp_normal;

	t_cam		cam;

	int			boost;
	double		gamma;
	int			spec;
	int			x;
	int			y;

	double		u;
	double		v;

	double		a;
	double		b;
	double		c;

	double		t1;
	double		t2;

	double		m;

	t_info		info;
	t_info		info_flags;
	t_vector	raydir;
	t_ray		ray;

	t_ires		ires;
	t_ires		temp_ires;
	t_color		final_color;
	t_color		specular;

	t_sphere	*sphere;
	t_cylinder	*cylinder;
	t_plane		*plane;
	t_cone		*cone;
	t_light		*light;

	double 		rec_depth;
	double		mirror_coef;
	double		fuck_up_coef;
	t_vector	something;
	t_color		color;
	t_color		color_backup;
	double		ray_dist;
	double		ray_dist_backup;
	t_vector	normal;

	int			hit;
	int			hit_shadow;

	double		d;
	double		s;
	double		light_dist;

	t_vector	hit_point;
	t_vector	light_ray_dir;

	double		move_x;
	double		move_y;
	double		move_z;
	double		fov;
	double		alpha_x;
	double		alpha_y;
	double		alpha_z;
//------
	int 		neg;
	t_sphere 	nsphere;
	t_cylinder 	ncyl;
	t_cube		ncube;
	t_torus torus;
}				t_data;

int				rtv_exit(t_data *d);
int				key_press(int key, t_data *d);
int				key_release(int key, t_data *d);
int				expose(t_data *d);
int				intersect_something(t_data *d);
void			draw(t_data *d);
void			assign_image(int x, int y, t_color color, t_data *d);
void			data_init(t_data *d);
void			read_info(char *file, t_data *d);
void			init_temp_res(t_color col, t_vector vec, t_data *d);
void			plane_sphere_part(t_data *d);
void			light_and_shadows(t_data *d);
void			camera_and_rays(t_data *d);
void			shadows_and_light(t_data *d);
t_color			get_image(int x, int y, t_data *d);

int				sphere_intersect(t_data *d, t_sphere sphere);
int				plane_intersect(t_data *d, t_plane plane);
int				cylinder_intersect(t_data *d, t_cylinder cylinder);
int				cone_intersect(t_data *d, t_cone cone);
int				disc_intersect(t_data *d, t_plane plane, double r);

t_sphere		init_sphere(t_vector pos, double radius, t_color col);
t_light			init_light(t_vector pos, t_color col);
t_plane			init_plane(t_vector point, t_vector normal, t_color col);
t_cylinder		init_cylinder(t_vector pos, t_vector dir, double r, t_color c);
t_cone			init_cone(t_vector pos, t_vector dir, double angle, t_color c);
t_ray			init_ray(t_vector origin, t_vector dir, double dist);
t_cam			init_cam(t_vector dir, t_vector pos, double fov);
t_color			init_color(double r, double g, double b);

t_vector		vinit(double x, double y, double z);
t_vector		vsub(t_vector v1, t_vector v2);
t_vector		vadd(t_vector v1, t_vector v2);
t_vector		vmul(t_vector v1, double l);
double			vlen(t_vector v1);
t_vector		vnorm(t_vector v1);
double			vdot(t_vector v1, t_vector v2);

t_vector		rotatex(t_vector vec, double alpha);
t_vector		rotatey(t_vector vec, double alpha);
t_vector		rotatez(t_vector vec, double alpha);

t_color			col_mix(t_color base, t_color col2);
t_color			col_mult_d(t_color col1, double d);
t_color			col_mult(t_color col1, t_color col2);
t_color			col_norm(int col);
t_color			col_avg(t_color col1, t_color col2);
t_color			col_clamp(t_color col1);
t_color			col_add(t_color col1, t_color col2);
double			quad_equation_t1(double a, double b, double c);
double			quad_equation_t2(double a, double b, double c);

t_color			norm_hex(int col);
double			ft_atof(char *str);
int				ft_atoi_hex(char *str);

double 			PerlinNoise2D(double x, double y);
int 			cube_intersect(t_data *d, t_cube cube);
t_cube			init_cube(t_vector pos, t_vector dir, double l, t_color col);

// double 			*solve_quartic(double a, double b, double c, double d, double e);
// double 			*solve_cubic(double a, double b, double c, double d);
t_torus			init_torus(t_vector pos, t_vector dir, double rin, double rout, t_color c);
int				torus_intersect(t_data *f, t_torus torus);
int				solve_quartic(double b, double c, double d, double e, double **roots);
t_complex		sqrt_complex(t_complex c);
#endif
