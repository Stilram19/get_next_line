/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obednaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 14:41:44 by obednaou          #+#    #+#             */
/*   Updated: 2022/11/02 14:45:38 by obednaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (*(s + i))
	{
		if (*(s + i) == (char)c)
			return ((char *)s + i);
		i++;
	}
	if (!(char)c)
		return ((char *)s + i);
	return (0);
}

void	update_static(char **ptr_to_static)
{
	size_t	i;
	size_t	j;
	size_t	len;
	char	*buff;

	j = 0;
	i = _ft_strlen(*ptr_to_static, 10);
	len = _ft_strlen(*ptr_to_static, 0) - i;
	if (!len)
	{
		kicking_leaks_away(ptr_to_static);
		return ;
	}
	buff = malloc(sizeof(char) * (len + 1));
	while (buff && j < len)
	{
		*(buff + j) = *(*ptr_to_static + i + j);
		j++;
	}
	if (buff)
		*(buff + j) = 0;
	free(*ptr_to_static);
	*ptr_to_static = buff;
}

void	kicking_leaks_away(char **ptr)
{
	if (*ptr)
	{
		free(*ptr);
		*ptr = 0;
	}
}

size_t	_ft_strlen(const char *str, int end)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (*(str + i) && *(str + i) != end)
		i++;
	if (*(str + i) == 10)
		i++;
	return (i);
}

int	_ft_strjoin(char **ptr_to_static, char *buff)
{
	size_t	i;
	size_t	j;
	size_t	size;
	char	*join_buff;

	i = 0;
	j = -1;
	size = _ft_strlen(*ptr_to_static, 0) + _ft_strlen(buff, 0) + 1;
	join_buff = malloc(size * sizeof(char));
	if (!join_buff)
		return (-1);
	while (*ptr_to_static && *(*ptr_to_static + i))
	{
		*(join_buff + i) = *(*ptr_to_static + i);
		i++;
	}
	while (*(buff + ++j))
		*(join_buff + i + j) = *(buff + j);
	*(join_buff + i + j) = 0;
	kicking_leaks_away(ptr_to_static);
	*ptr_to_static = join_buff;
	return (1);
}
