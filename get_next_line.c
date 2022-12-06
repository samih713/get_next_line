/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdelra <sabdelra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 01:33:11 by sabdelra          #+#    #+#             */
/*   Updated: 2022/12/07 02:36:13 by sabdelra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char		*stash;
	size_t			buffer_size = BUFFER_SIZE;
	int				read_return;
	char			buffer[BUFFER_SIZE + 1];

	if(fd < 0 || buffer_size <= 0)
		return (0);
	if (!stash)
		stash = "";
	read_return = 1;
	while (new_line(stash) == 0 && read_return > 0)
	{
		read_return = read(fd, buffer, buffer_size);
		if (read_return < 0)
			return(NULL);
		buffer[read_return] = '\0';
		join(&stash, buffer, read_return); // optimize this by starting stash after the previous loop run
		if (read_return == 0)
			break;
	}
	if (stash[0] == '\0')
		return(NULL);
	return(shift_left(&stash));
}

int main(void)
{
	int fd = open("file1.txt", O_RDONLY);
	for(int i = 0; i < 13; i++)
	{

		printf("%s\n", get_next_line(fd));
		printf("*******************************************\n");
	}
	//free(s);
}
