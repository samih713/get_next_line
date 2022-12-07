/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdelra <sabdelra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 01:32:03 by sabdelra          #+#    #+#             */
/*   Updated: 2022/12/07 21:21:28 by sabdelra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 5
#endif

char	*get_next_line(int fd);
int		new_line(char *stash);
void	join(char **stash, char *buffer, int read_return);
size_t ft_strlen(char *str);
char	*shift_left(char **stash);
void	*ft_memmove(void *dest, const void *src, size_t size);
size_t	ft_strlcat(char *dst,char *src, size_t size);
void	ft_bzero(void *s, size_t n);

#endif
