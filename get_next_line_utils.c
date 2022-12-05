/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdelra <sabdelra@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 02:53:41 by sabdelra          #+#    #+#             */
/*   Updated: 2022/12/05 02:53:41 by sabdelra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <string.h>
//#include <unistd.h>

/*
Parse the stash, should be the last function to call before output
Returns a string ending at the first \n it encounters (only call this function when stash has \n)
shifts everything after \n into a new location (frees old pointer) and returns a new pointer
[to-do] need to maintain index
[to-do] include ft_memmove
[to-do] check if **stash works as static, might not work as its setting a new location
[to-do] function to join buffers to stash
[to-do] function to check stash for \n
*/
char	*shift_left(char **stash)
{
	char	*return_string;
	char	*temp;
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	// care precedence || *stash[i] = *(stash[i])     [] higher than *
	while((*stash)[i] != '\n')
		i++;
	return_string = (char *)malloc(i + 2); // + 2 to include the \n and \0
	if (!return_string)
		return (0);
	memmove(return_string, *stash, i + 1);
	return_string[i + 1] = '\0';
	while((*stash)[i + j]) // j reach the null
		j++; //assume j=2
	temp = (char *)malloc(sizeof(char) * (j)); //malloc 3
	if (!return_string)
		return (0);
	temp[j - 1] = '\0'; // temp [2]
	memmove(temp, *stash+i+1, j); // copy 2 characters the 3rd is null ^^
	free(*stash);
	*stash = temp;
	return(return_string);
}

size_t ft_strlen(char *str)
{
	if(!*str)
		return (0);
	return (1 + ft_strlen(str + 1));
}

char	*join(char *stash, char *buffer)
{
	char *new_stash;
	size_t stash_length;
	size_t buffer_length;

	stash_length = ft_strlen(stash);
	buffer_length = ft_strlen(buffer);
	new_stash = (char *)malloc(stash_length + buffer_length + 1);
	memmove(new_stash, stash, stash_length);
	strncat(new_stash, buffer, buffer_length);
	new_stash[stash_length + buffer_length] = '\0';
	return(new_stash);
}

int	new_line(char *stash)
{
	int i;

	i = 0;
	while(stash[i])
	{
		if(stash[i] != '\n')
			return (1);
	}
	return (0);
}

/* // testing join
int main(void)
{
	char *buffer = "Hello!";
	char *stash = malloc(5);
	static char *statiko;
	stash = "new1";
	stash = join(stash, buffer);
	stash = join(stash, "welcome");
	statiko = stash;
	printf("%s\n", statiko);
}
 */

// testing shift_left
int main(void)
{
	size_t stash_size = 1024;
	char *stash = (char *)malloc(100);
	if(!stash)
		return (0);
	memmove(stash, "Hello\nKeep this", stash_size);
	printf("Return string = %s", shift_left(&stash));
	printf(">>>\n\n--------------------------\n\n");
	for(int i = 0; i < 8; i++)
	{
		printf("%c", (char)stash[i]);
	}
	printf("\n\n--------------------------\n\n");
}

