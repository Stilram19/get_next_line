/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obednaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 17:55:57 by obednaou          #+#    #+#             */
/*   Updated: 2022/10/31 15:06:11 by obednaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	clean_it_up(char **ptr_to_static, char **ptr_to_line)
{
	size_t	i;
	size_t	line_len;

	i = 0;
	if (*ptr_to_static)
		line_len = _ft_strlen(*ptr_to_static, 10);
	if (!line_len || !(*permanent_buff))
	{
		*ptr_to_line = 0;
		return (0);
	}
	*ptr_to_line = malloc(sizeof(char) * (line_line + 1));
	while (i < line_line)
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
	if (!sys_call_ret && (sys_call_ret + 1))
		sys_call_ret = -1;
	while (buff && sys_call_ret && (sys_call_ret + 1))
	{
		*(buff + BUFFER_SIZE) = 0;
		sys_call_ret = ft_strjoin(ptr_to_static, buff);
		if ((sys_call_ret + 1) && ft_strchr(*ptr_to_static, 10))
			return ;
		if (sys_call_ret + 1)
			buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
		if ((sys_call_ret + 1) && buff)
			sys_call_ret = read(fd, buff, BUFFER_SIZE);
	}
	if (!(sys_call_ret + 1))
		kicking_leaks_away(buff, ptr_to_static);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*permanent_buffer;

	if (!(fd >= 0 || BUFFER_SIZE > 0))
		return (0);
	grab_next_line(&permanent_buffer, fd);
	clean_it_up(permanent_buffer, &line);
	return (line);
}
