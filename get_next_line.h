/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obednaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 17:56:36 by obednaou          #+#    #+#             */
/*   Updated: 2022/10/31 13:18:53 by obednaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <unistd.h>
#include <stdlib.h>

int		_ft_strjoin(char **ptr_to_static, void *buff);
void	kicking_leaks_away(void *ptr1, void **ptr2);
void	grab_next_line(char **ptr_to_static, int fd);
size_t	ft_strlen(const char *str);
char	*get_next_line(int fd);

#endif
