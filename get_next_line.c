/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afelicia <afelicia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 17:54:03 by afelicia          #+#    #+#             */
/*   Updated: 2022/06/22 17:46:41 by afelicia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_read(int fd, char **save, char **tmp)
{
	char	*buf;
	ssize_t	retval;

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
		ft_free(tmp, 0, 0);
		if (ft_strchr(*save, '\n'))
			break ;
	}
	ft_free(&buf, 0, 0);
}

char	*ft_saving(char *tmp)
{
	char	*save;
	size_t	i;
	size_t	j;

	i = 0;
	if (!(ft_strchr(tmp, '\n')))
		return (NULL);
	while (tmp[i] != '\n')
		i++;
	save = calloc((ft_strlen(tmp) - i) + 1, sizeof(char));
	if (save == NULL)
		return (NULL);
	i = i + 1;
	j = 0;
	while (tmp[i] != '\0')
	{
		save[j] = tmp[i];
		i++;
		j++;
	}
	return (save);
}

char	*ft_splitn(char **save, char **tmp)
{
	char	*print;
	size_t	i;
	char	*str;

	i = 0;
	*tmp = ft_strdup(*save);
	ft_free(0, save, 0);
	str = ft_strdup(*tmp);
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	print = calloc(i + 2, sizeof(char));
	if (print == NULL)
		return (NULL);
	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
	{
		print[i] = str[i];
		i++;
		if (str[i] == '\n')
			break ;
	}
	print[i] = str[i];
	*save = ft_saving(*tmp);
	ft_free(0, &str, tmp);
	return (print);
}

char	*get_next_line(int fd)
{
	static char	*save = NULL;
	char		*print;
	char		*tmp;

	print = NULL;
	tmp = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	ft_read(fd, &save, &tmp);
	if (save != NULL && *save != '\0')
	{
		print = ft_splitn(&save, &tmp);
	}
	if (print == NULL)
	{
		ft_free(&save, &print, &tmp);
		return (NULL);
	}
	return (print);
}

/*void	ft_exit(void)
{
	system("leaks -q a.out");
}

int	main(void)
{
	int	fd;
	char	*a;

	atexit(ft_exit);
	fd = open("input.txt", O_RDONLY);
	a = get_next_line(fd);
	while (a != NULL)
	{
		puts (a);
		ft_free(&a, 0, 0);
		a = get_next_line(fd);
	}
	ft_free(&a, 0, 0);
}*/