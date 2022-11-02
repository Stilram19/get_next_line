/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obednaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 14:41:24 by obednaou          #+#    #+#             */
/*   Updated: 2022/11/02 14:46:35 by obednaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	clean_it_up(char **ptr_to_static, char **ptr_to_line)
{
	size_t	i;
	size_t	line_len;

	i = 0;
	if (*ptr_to_static)
	{
		line_len = _ft_strlen(*ptr_to_static, 10);
		*ptr_to_line = malloc(sizeof(char) * (line_len + 1));
	}
	if (!(*ptr_to_line && *ptr_to_static))
	{
		kicking_leaks_away(ptr_to_static);
		*ptr_to_line = 0;
		return ;
	}
	while (i < line_len)
	{
		*(*ptr_to_line + i) = *(*ptr_to_static + i);
		i++;
	}
	*(*ptr_to_line + i) = 0;
	update_static(ptr_to_static);
}

void	grab_next_line(char **ptr_to_static, int fd)
{
	char	*buff;
	int		sys_call_ret;

	sys_call_ret = 1;
	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (buff)
		sys_call_ret = read(fd, buff, BUFFER_SIZE);
	while (buff && sys_call_ret && (sys_call_ret + 1))
	{
		*(buff + sys_call_ret) = 0;
		sys_call_ret = _ft_strjoin(ptr_to_static, buff);
		if ((sys_call_ret + 1) && ft_strchr(*ptr_to_static, 10))
			break ;
		if ((sys_call_ret + 1))
			sys_call_ret = read(fd, buff, BUFFER_SIZE);
	}
	if (!(sys_call_ret + 1) || !buff)
		kicking_leaks_away(ptr_to_static);
	free(buff);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*permanent_buffers[256];

	if (!(fd >= 0 && fd < 256 && BUFFER_SIZE > 0))
		return (0);
	grab_next_line(permanent_buffers + fd, fd);
	clean_it_up(permanent_buffers + fd, &line);
	return (line);
}
