/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 15:25:00 by marvin            #+#    #+#             */
/*   Updated: 2022/05/20 15:25:00 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h> // to manipulate a file in c for functions readonly write only read write 

char	*get_next_line(int fd);
void	ft_read(int fd, char **save, char **tmp);
char	*ft_saving(char *tmp);
char	*ft_splitn(char **save, char **tmp);
char	*ft_strjoin(char const *s1, char const *s2);
void	ft_free(char **str, char **str2, char **str3);
char	*ft_strdup(const char *s);
char	*ft_strchr(char *str, int c);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *str);

#endif
