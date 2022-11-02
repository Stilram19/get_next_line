/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obednaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 17:56:36 by obednaou          #+#    #+#             */
/*   Updated: 2022/11/02 12:31:29 by obednaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

int		_ft_strjoin(char **ptr_to_static, char *buff);
void	update_static(char **ptr_to_static);
void	clean_it_up(char **permanent_buff, char **ptr_to_line);
void	kicking_leaks_away(void *ptr1, char **ptr2);
void	grab_next_line(char **ptr_to_static, int fd);
char	*ft_strchr(const char *s, int c);
char	*get_next_line(int fd);
size_t	_ft_strlen(const char *str, int end);
#endif
