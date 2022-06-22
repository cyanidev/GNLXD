/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afelicia <afelicia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 11:02:56 by afelicia          #+#    #+#             */
/*   Updated: 2022/06/22 11:51:28 by afelicia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <stddef.h>
# include <stdio.h> //print
# include <stdlib.h> //malloc
# include <string.h> 
# include <unistd.h> // read
# include <fcntl.h> //open

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

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
