/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdelra <sabdelra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 02:53:41 by sabdelra          #+#    #+#             */
/*   Updated: 2022/12/08 00:03:57 by sabdelra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <string.h>

char	*shift_left(char **stash)
{
	char	*return_string;
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	while((*stash)[i] != '\n' && (*stash)[i])
		i++;
	if ((*stash)[i] == '\0')
	{
		return_string = (char *)malloc(i + 2);
		if (!return_string)
			return (NULL);
		ft_memmove(return_string, *stash, i + 1);
	}
	else
	{
		return_string = (char *)malloc(i + 2);
		if (!return_string)
			return (0);
		ft_memmove(return_string, *stash,i + 1);
	}
	return_string[i + 1] = '\0';
	while((*stash)[i + j++])
		;
	ft_memmove(*stash, *stash + i + 1, j);
	if (*stash && !**stash)
	{
		free(*stash); //
		*stash = NULL;
	}
	return(return_string);
}

size_t ft_strlen(char *str)
{
	size_t i;

	i = 0;
	if(str[0] == '\0')
		return(0);
	while(str[i])
		i++;
	return (i);
}

void	join(char **stash, char *buffer, int buffer_length)
{
	char *new_stash;
	size_t stash_length;

	if (*stash)
		stash_length = ft_strlen(*stash);
	else
		stash_length = 0;
	new_stash = (char *)malloc(stash_length + buffer_length + 1);
	if(!new_stash)
		return ;
	ft_memmove(new_stash, *stash, stash_length + 1);
	strncat(new_stash, buffer, buffer_length);
	new_stash[stash_length + buffer_length] = '\0';
	if (**stash)
		free(*stash);
	*stash = new_stash;
	if(new_stash[0] == '\0')
	{
		free(new_stash);
		*stash = NULL;
	}
}

int	new_line(char *stash)
{
	int i;

	i = 0;
	while(stash && stash[i])
	{
		if(stash[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

void	*ft_memmove(void *dest, const void *src, size_t size)
{
	int	i;

	if (!dest && !src)
		return (NULL);
	if (dest < src)
	{
		i = 0;
		while (i < (int)size)
		{
			((char *)dest)[i] = ((char *)src)[i];
			i++;
		}
	}
	else
	{
		i = (int)size - 1;
		while (i >= 0)
		{
			((char *)dest)[i] = ((char *)src)[i];
			i--;
		}
	}
	return (dest);
}

size_t	ft_strlcat(char *dst,char *src, size_t size)
{
	size_t	i;
	int		j;
	int		length;

	if (!dst && !size)
		return (0);
	length = ft_strlen(dst);
	if (size <= ft_strlen(dst))
		return (size + ft_strlen(src));
	i = ft_strlen((char *)dst);
	j = 0;
	while (src[j] != '\0' && i < size)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	//dst[i] = '\0';
	return (length + ft_strlen(src));
}
