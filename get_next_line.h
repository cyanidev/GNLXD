/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afelicia <afelicia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 17:55:17 by afelicia          #+#    #+#             */
/*   Updated: 2022/05/27 23:00:03 by afelicia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stddef.h>
# include <stdio.h> //print
# include <stdlib.h> //malloc
# include <string.h> 
# include <unistd.h> // read
# include <fcntl.h>

char	*get_next_line(int fd);
void	ft_read(int fd, char **save, char **tmp);
char	*ft_saving(char *tmp);
char	*ft_splitn(char **save, char **tmp);
char	*ft_strjoin(char const *s1, char const *s2);
void	ft_free(char **str, char **str2, char **str3);
char	*ft_strdup(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *str);

#endif 
