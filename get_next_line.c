/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afelicia <afelicia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 17:54:03 by afelicia          #+#    #+#             */
/*   Updated: 2022/05/27 23:02:49 by afelicia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#ifndef BUFFSIZE
# define BUFFSIZE 100
#endif

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*snew;
	size_t	i;
	size_t	j;
	size_t	len;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len = strlen(s1) + strlen(s2) + 1;
	snew = malloc(sizeof(char) * (len + 1));
	if (snew == NULL)
		return (NULL);
	i = 0;
	while (i < strlen(s1))
	{
		snew[i] = s1[i];
		i++;
	}
	j = 0;
	while (j < strlen(s2))
	{
		snew[i + j] = s2[j];
		j++;
	}
	snew[i + j] = '\0';
	return (snew);
}

char	*get_next_line(int fd)
{
	ssize_t	retval;
	char	buff[BUFFSIZE + 1];
	static	char *save = "";
	char	*tmp;
	size_t	size;
	char	*print;
	size_t	move;

	retval = 1;
	while (retval != 0 && strchr(save,'\n') == NULL)
	{
		retval = read(fd, buff, BUFFSIZE);
		if (retval == -1)
		{
			if (strlen(save) > 0)
			{
				free(save);
				save = "";
			}
				return(NULL);
		}
		buff[retval] = '\0';
		tmp = ft_strjoin(save, buff);
		if (tmp == 0)
		{
			free(save);
			save = "";
			return (NULL);
		}
		if (strlen(save) > 0)
			free(save);
		save = tmp;
	}
	size = strchr(save,'\n') - &save[0];//y si no hay '\n'? 
	print = malloc(sizeof(char *) * (size + 2));
	if (print == NULL)
	{
		if (strlen(save) == 0)
			free (save);
		save = "";
		return (NULL);
	}
	memcpy(print, save, size);
	print[size] = '\0';
	move = strlen(save) - strlen(print);
	memmove(&save[0],&save[strlen(print) + 1], move);
	if (strlen(save) == 0)
	{
		free(save);
		save = "";
		return (NULL);
	}
	if (strlen(print) == 0)
	{
		free(print);
		return (NULL);
	}
	return (print);
}


/*int	main(void)
{
	int	txt;
	txt = open("", O_RDONLY);

	for (int i = 0; i < 5; i++)
		puts(get_next_line(txt));
}*/

/*#include <fcntl.h>
int open(const char *pathname, int flags);
The argument flags must include one of the following access
       modes: O_RDONLY, O_WRONLY, or O_RDWR.  These request opening the
       file read-only, write-only, or read/write, respectively.

llamar a read cada vez que no encuentres un salto y no llegue a EOF

hay que llamar a read tantas veces necesite el buffer*/

