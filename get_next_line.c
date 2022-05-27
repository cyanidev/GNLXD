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

char	*ft_read(int fd, nosetodavia)
{
	char	str1[BUFFSIZE + 1];
	char	*temp;
	char	*newstr;
	ssize_t	retval;
	static	char *remainder;
	char	*aux;

	temp = "";
	retval = read(fd, str1, BUFFSIZE);
	while (retval != 0)
	{
		if (ft_strchr(str1, '\n'))
		{
			if (*(ft_strchr(str1, '\n') + 1) != '\0')
			{
				aux = ft_strchr(str1, '\n') + 1;
				remainder = ft_strdup(aux);
				returnn (strndup(str1, aux - str1));
			}
		}
	}
	newstr = strjoin(str1, temp);
}

char	*get_next_line(int fd)
{

}
/*la_cantidad_que_consegui_leer = read(archivo, lugar_donde_guardo_lo_que_leo, la_cantidad_que_quiero_leer);

/*#include <fcntl.h>
int open(const char *pathname, int flags);
The argument flags must include one of the following access
       modes: O_RDONLY, O_WRONLY, or O_RDWR.  These request opening the
       file read-only, write-only, or read/write, respectively.

llamar a read cada vez que no encuentres un salto y no llegue a EOF

hay que llamar a read tantas veces necesite el buffer*/

