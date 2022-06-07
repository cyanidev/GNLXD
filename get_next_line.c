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

void	ft_read(int fd, char **save, char **tmp)
{
	char	*buf;
	ssize_t	retval;

	buf = malloc(sizeof (char) * BUFFSIZE + 1);
	if (buf == NULL)
		return (NULL);
	retval = 1;
	while (retval > 0)
	{
		retval = read(fd, buf, BUFFSIZE);
		if (retval == -1)
		{
			ft_free(buf, *save, *tmp);
			return (NULL);
		}
		buf[retval] = '\0';
		*tmp = ft_strdup(*save);
		free(save);
		*save = ft_strjoin(*tmp, buf);
		free(tmp);
		if (strchr(*save, '/n') != '\0')
			break ;
	}
}

char	*iminus(char	**save)
{
	char	*str;
	size_t	i;
	char	*print;

	str = ft_strdup(*save);
	i = strch(str, '\n') - strlen(str);
	while (str[i != 0])
	{
		print = str;
		i--;
	}
	return (print);
}

char	*ft_splitn(char **save)
{
	char	*print;

	print = iminus(**save);
	*save = iplus(**save);

	return (print);
}

char	*get_next_line(int fd)
{
	static char	*save = NULL;
	char		*print;
	char		*tmp;

	print = NULL;
	tmp = NULL;
	if (fd < 0 || BUFFSIZE < 0)
		return (NULL);
	ft_read(fd, &save, &tmp);
	while (strlen(save) > 0)
	{
		print = ft_splitn(&save);
	}
	if (print == NULL)
	{
		free(save);
		save = NULL;
		free(print);
		free(tmp);
		return (NULL);
	}
	return (print);
}

/*int	main(void)
{
	int	txt;
	txt = open("input.txt", O_RDONLY);
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

