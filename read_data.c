/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izelensk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 16:49:51 by izelensk          #+#    #+#             */
/*   Updated: 2017/07/07 16:49:53 by izelensk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "get_next_line.h"
#define SC sphere_count
#define CC cone_count
#define PC plane_count
#define LC light_count
#define YC cylinder_count
#define LA line_arr

void	check_params_count(int count, char **line_arr)
{
	int	i;
	int	n;

	n = 0;
	i = -1;
	while (line_arr[++i])
		n++;
	if (n == count)
		return ;
	write(1, "Wrong parameters count in file(\n", 32);
	exit(0);
}

void	alloc_objects(char **line_arr, t_data *d)
{
	if (ft_strequ(line_arr[0], "plane_count:"))
	{
		check_params_count(2, line_arr);
		d->info.PC = ft_atoi(line_arr[1]);
		d->plane = (t_plane *)malloc(sizeof(t_plane) * d->info.PC);
	}
	else if (ft_strequ(line_arr[0], "sphere_count:"))
	{
		check_params_count(2, line_arr);
		d->info.SC = ft_atoi(line_arr[1]);
		d->sphere = (t_sphere *)malloc(sizeof(t_sphere) * d->info.SC);
	}
	else if (ft_strequ(line_arr[0], "cylinder_count:"))
	{
		check_params_count(2, line_arr);
		d->info.YC = ft_atoi(line_arr[1]);
		d->cylinder = (t_cylinder *)malloc(sizeof(t_cylinder) * d->info.YC);
	}
	else if (ft_strequ(line_arr[0], "cone_count:"))
	{
		check_params_count(2, line_arr);
		d->info.CC = ft_atoi(line_arr[1]);
		d->cone = (t_cone *)malloc(sizeof(t_cone) * d->info.CC);
	}
}

void	init_objects_one(char **line_arr, t_data *d)
{
	if (ft_strequ(LA[0], "camera:"))
	{
		check_params_count(8, LA);
		d->cam = init_cam(vinit(ft_atof(LA[1]), ft_atof(LA[2]),
		ft_atof(LA[3])), vnorm(vinit(ft_atof(LA[4]), ft_atof(LA[5]),
		ft_atof(LA[6]))), ft_atof(LA[7]));
	}
	else if (ft_strequ(LA[0], "sphere:") && d->info_flags.SC < d->info.SC)
	{
		check_params_count(6, LA);
		d->sphere[d->info_flags.SC++] = init_sphere(vinit(ft_atof(LA[1]),
		ft_atof(LA[2]), ft_atof(LA[3])),
		ft_atof(LA[4]),
		norm_hex(ft_atoi_hex(LA[5])));
	}
	else if (ft_strequ(LA[0], "plane:") && d->info_flags.PC < d->info.PC)
	{
		check_params_count(8, LA);
		d->plane[d->info_flags.PC++] = init_plane(vinit(ft_atof(LA[1]),
		ft_atof(LA[2]), ft_atof(LA[3])), vnorm(vinit(ft_atof(LA[4]),
		ft_atof(LA[5]), ft_atof(LA[6]))), norm_hex(ft_atoi_hex(LA[7])));
	}
}

void	init_objects_two(char **line_arr, t_data *d)
{
	if (ft_strequ(LA[0], "light:") && d->info_flags.LC < d->info.LC)
	{
		check_params_count(5, LA);
		d->light[d->info_flags.LC++] = init_light(vinit(ft_atof(LA[1]),
		ft_atof(LA[2]), ft_atof(LA[3])), norm_hex(ft_atoi_hex(LA[4])));
	}
	else if (ft_strequ(LA[0], "cylinder:") && d->info_flags.YC < d->info.YC)
	{
		check_params_count(9, LA);
		d->cylinder[d->info_flags.YC++] = init_cylinder(vinit(ft_atof(LA[1]),
		ft_atof(LA[2]), ft_atof(LA[3])), vnorm(vinit(ft_atof(LA[4]),
		ft_atof(LA[5]), ft_atof(LA[6]))), ft_atof(LA[7]),
		norm_hex(ft_atoi_hex(LA[8])));
	}
	else if (ft_strequ(LA[0], "cone:") && d->info_flags.CC < d->info.CC)
	{
		check_params_count(9, LA);
		d->cone[d->info_flags.CC++] = init_cone(vinit(ft_atof(LA[1]),
		ft_atof(LA[2]), ft_atof(LA[3])), vnorm(vinit(ft_atof(LA[4]),
		ft_atof(LA[5]), ft_atof(LA[6]))), TANG(ft_atof(LA[7])) / 2.0,
		norm_hex(ft_atoi_hex(LA[8])));
	}
	d->temp = -1;
}

void	read_info(char *file, t_data *d)
{
	int		fd;
	char	**line_arr;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		rtv_exit(d);
	while (get_next_line(fd, &line) == 1)
	{
		line_arr = ft_strsplit(line, ' ');
		alloc_objects(line_arr, d);
		if (ft_strequ(line_arr[0], "light_count:"))
		{
			check_params_count(2, line_arr);
			d->info.LC = ft_atoi(line_arr[1]);
			d->light = (t_light *)malloc(sizeof(t_light) * d->info.LC);
		}
		init_objects_one(line_arr, d);
		init_objects_two(line_arr, d);
		while (line_arr[++d->temp])
			free(line_arr[d->temp]);
		free(line_arr);
		free(line);
	}
	close(fd);
}
