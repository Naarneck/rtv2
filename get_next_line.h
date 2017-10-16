/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izelensk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 13:49:31 by izelensk          #+#    #+#             */
/*   Updated: 2017/03/10 13:49:38 by izelensk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 132
# define NUM_FILES 4096
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include "libft/libft.h"

typedef	struct	s_fds
{
	char		*str[NUM_FILES];
	int			fd;
	int			size[NUM_FILES];
}				t_fds;

int				get_next_line(const int fd, char **line);

#endif
