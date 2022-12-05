/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdelra <sabdelra@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 01:33:11 by sabdelra          #+#    #+#             */
/*   Updated: 2022/12/04 01:33:11 by sabdelra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char		*stash; //should be able to just add buffers to it [stash <-- buffer <-- buffer ...]
	size_t			buffer_size = BUFFER_SIZE;
	int				read_return;

	char *buffer, *return_string;

	buffer = (char *)malloc(buffer_size + 1);
	buffer[buffer_size] = '\0';
	if(!buffer)
		return (0);
	while (new_line(stash) == 0 || read_return < buffer_size) // return < size means either -1,0, close to end
	{
		read_return = read(fd, buffer, buffer_size); // [to-do] test if read clears the buffer
		stash = join(stash, buffer, read_return);
	}
	return(shift_left(&stash));
}



/*
test whether read clears the buffer or no
int main(void)
{
	char *buff;
	buff = malloc(4);
	buff[3] = '\0';
	int fd = open("file1.txt", O_RDONLY);
	for(int i = 0; i < 5; i++)
	{
		_read(fd, buff, 3);
		printf("%s\n", buff);
	}
}
 */
