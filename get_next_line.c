/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obednaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 17:55:57 by obednaou          #+#    #+#             */
/*   Updated: 2022/10/31 14:05:16 by obednaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*clean_it_up(char **ptr_to_static)
{
	char	*buff1;
	char	*buff2;
	int		len1;
	int		len2;

	if (!(*ptr_to_static))
		return (0);
	len1 = _ft_strlen(*ptr_to_static, 10);
	len2 = _ft_strlen(*ptr_to_static + len1, 0);
	if (!len1)
		buff1 = 0;
	else
		buff1 = malloc(sizeof(char) * (len1 + 1));
	if (!len2)
		buff2 = 0;
	else
		buff2 = malloc(sizeof(char) * (len2 + 1));
	*(buff1 + len1) = 0;
	while (buff2 && len2 >= len1 - 1)
		*(buff2 + len2--) = *(*ptr_to_static + len1);
	while (buff2 && len2--)
		*(buff2 + len2) = *(*ptr_to_static + len2);
	free(*ptr_to_static);
	*ptr_to_static = buff1;
	return (buff2);
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
	clean_it_up(&line, permanent_buffer);
	return (line);
}
