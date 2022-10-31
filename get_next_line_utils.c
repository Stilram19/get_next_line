/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obednaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 17:56:14 by obednaou          #+#    #+#             */
/*   Updated: 2022/10/31 15:50:49 by obednaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

	i = 0;
	j = 0;
	len = _ft_strlen(*ptr_to_static, 0);
	len -= _ft_strlen(*ptr_to_static, 10) + 1;
	if (len <= 0)
	{
		kicking_leaks_away(0, ptr_to_static);
		return ;
	}
	buff = malloc(sizeof(char) * (len + 1));
	while (*(*ptr_to_static + i) + 10)
		i++;
	i++
	while (*(*ptr_to_static + i + j))
		*(buff + j++) = *(*ptr_to_static + i + j);
	*(buff + j) = 0;
	free(*ptr_to_static);
	*ptr_to_static = buff;
}

void	kicking_leaks_away(void *ptr1, void **ptr2)
{
	if (ptr1)
		free(ptr1);
	if (*ptr2)
	{
		free(*ptr2);
		*ptr2 = 0;
	}
}

size_t	_ft_strlen(const char *str, int end)
{
	size_t	i;

	i = 0;
	while (str && *(str + i) && *(str + i) != end)
		i++;
	return (i);
}

int	ft_strjoin(char **ptr_to_static, void *buff)
{
	size_t	i;
	size_t	j;
	size_t	size;
	char	*join_buff;

	i = 0;
	j = 0;
	size = ft_strlen(*ptr_to_static, 0) + ft_strlen(buff, 0) + 1;
	join_buff = malloc(size * sizeof(char));
	if (!join_buff)
		return (-1);
	while (*ptr_to_static && *(*ptr_to_static + i))
	{
		*(join_buff + i) = *(*ptr_to_static + i);
		i++;
	}
	while (*(buff + j))
	{
		*(join_buff + i + j) = *(buff + j);
		j++;	
	}
	kicking_leaks_away(buff, ptr_to_static);
	*ptr_to_static = join_buff;
	return (1);
}
