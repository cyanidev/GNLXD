/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afelicia <afelicia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 11:02:59 by afelicia          #+#    #+#             */
/*   Updated: 2022/06/22 18:26:11 by afelicia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
	static char	*save[1024] = {NULL};
	char		*print;
	char		*tmp;

	print = NULL;
	tmp = NULL;
	if (fd < 0 || fd > 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	ft_read(fd, &save[fd], &tmp);
	if (save[fd] != NULL && *save[fd] != '\0')
	{
		print = ft_splitn(&save[fd], &tmp);
	}
	if (print == NULL)
	{
		ft_free(&save[fd], &print, &tmp);
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
	int fd[4];
	char *a;
	char *b;
	char *c;

	atexit(ft_exit);
	fd[1] = open("input.txt", O_RDONLY);
	fd[2] = open("input1.txt", O_RDONLY);
	fd[3] = open("input2.txt", O_RDONLY);
	a = get_next_line(fd[1]);
	b = get_next_line(fd[2]);
	c = get_next_line(fd[3]);
	while (a || b || c)
	{
		if (a)
		{
			puts(a);
			ft_free(&a, 0 ,0);
		}
		if (b)
		{
			puts(b);
			ft_free(&b, 0, 0);
		}
		if (c)
		{
			puts(c);
			ft_free(&c, 0, 0);
		}
		a = get_next_line(fd[1]);
		b = get_next_line(fd[2]);
		c = get_next_line(fd[3]);
	}
}*/