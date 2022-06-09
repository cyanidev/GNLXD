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

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 100
#endif

void	ft_read(int fd, char **save, char **tmp)
{
	char	*buf;
	ssize_t retval;

	buf = malloc(sizeof (char) * BUFFER_SIZE + 1);
	if (buf == NULL)
		return ;
	retval = 1;
	while (retval > 0)
	{
		retval = read(fd, buf, BUFFER_SIZE);
		if (retval == -1)
		{
			ft_free(&buf, save, tmp);
			return ;
		}
		buf[retval] = '\0';
		*tmp = ft_strdup(*save);
		ft_free(0, save, 0);
		*save = ft_strjoin(*tmp, buf);
		ft_free(0, 0, tmp);
		if (ft_strchr(*save, '\n') != '\0')
			break ;
	}
	ft_free(&buf, 0, 0);
}

char	*ft_saving(char *tmp)
{
	char	*save;
	size_t	i;

	i = 0;
	if (ft_strchr(tmp, '\0') == NULL)
		return (NULL);
	while (tmp[i] != '\n')
		i++;
	save = calloc((ft_strlen(tmp) - i) + 2, sizeof(char));
	if (save == NULL)
		return (NULL);
	i = i + 2;
	while (tmp[i] != '\0')
	{
		save[0] = tmp[i];
		i++;
		save++;
	}
	return (save);
}

char	*ft_splitn(char **save, char **tmp)
{
	char	*print;
	size_t	i;

	i = 0;
	*tmp = ft_strdup(*save);
	ft_free(0, save, 0);
	while(tmp[i] != '\n' && tmp[i] != '\0')
		i++;
	print = calloc(i + 2, sizeof(char));
	if (print == NULL)
		return (NULL);
	i = 0;
	while (tmp[i - 1] != '\n' && tmp[i] != '\0')
	{
		print[i] = tmp[i];
		i++;
	}
	*save = ft_saving(*tmp);
	ft_free(0, 0, tmp);
	return (print);
}

char	*get_next_line(int fd)
{
	static char	*save = NULL;
	char		*print;
	char		*tmp;

	print = NULL;
	tmp = NULL;
	if (fd <= 0 || BUFFER_SIZE <= 0)
		return (NULL);
	ft_read(fd, &save, &tmp);
	if (strlen(save) > 0)
	{
		print = ft_splitn(&save, &tmp);
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

int	main(void)
{
	int txt;
	txt = open("input.txt", O_RDONLY);
	for (int i = 0; i < 5; i++)
		puts(get_next_line(txt));
}

/*int	main(void)
{
	int	txt;
	txt = open("", O_RDONLY);

	for (int i = 0; i < 5; i++)
		puts(get_next_line(txt));
}*/
