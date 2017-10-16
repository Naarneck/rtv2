/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izelensk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 15:14:54 by izelensk          #+#    #+#             */
/*   Updated: 2017/01/13 15:14:56 by izelensk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#define BS BUFF_SIZE

char	*get_line(t_fds *fds, int size, int fd)
{
	char *ret;
	char *temp;

	temp = ft_strsub((*fds).str[fd], size, ft_strlen((*fds).str[fd]) - size);
	if ((*fds).size[fd] != 0)
		size--;
	ret = ft_strnew(size);
	while (size--)
		ret[size] = (*fds).str[fd][size];
	free((*fds).str[fd]);
	(*fds).str[fd] = ft_strdup(temp);
	free(temp);
	return (ret);
}

void	line_extrude(t_fds *fds, char *str, int fd)
{
	char *temp;

	str[(*fds).size[fd]] = '\0';
	temp = ft_strjoin((*fds).str[fd], str);
	free((*fds).str[fd]);
	(*fds).str[fd] = ft_strdup(temp);
	free(temp);
}

int		find_nbs(t_fds *fds, int fd)
{
	int		i;

	i = 0;
	if (fd != (*fds).fd)
		(*fds).fd = fd;
	if ((*fds).str[fd] == NULL)
	{
		(*fds).size[fd] = 1;
		(*fds).str[fd] = ft_strnew(1);
		return (-2);
	}
	while ((*fds).str[fd][i] != '\0')
	{
		if ((*fds).str[fd][i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

int		get_next_line(const int fd, char **line)
{
	char			c[BUFF_SIZE + 1];
	static t_fds	fds;

	if (fd < 0 || fd > 2048 || BS < 1 || line == NULL || read(fd, 0, 0) == -1)
		return (-1);
	find_nbs(&fds, fd);
	while (fds.size[fd] > 0)
		if (find_nbs(&fds, fd) >= 0)
		{
			*line = get_line(&fds, find_nbs(&fds, fd) + 1, fd);
			return (1);
		}
		else
		{
			fds.size[fd] = read(fd, c, BUFF_SIZE);
			if (fds.size[fd] < 0)
				return (-1);
			line_extrude(&fds, c, fd);
		}
	if (fds.size[fd] == 0 && fds.str[fd][0] != '\0')
	{
		*line = get_line(&fds, ft_strlen(fds.str[fd]), fd);
		return (1);
	}
	return (0);
}
